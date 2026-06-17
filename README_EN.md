# CnComm - C++ Serial Communication Library

English | [中文](README.md)

CnComm is a cross-platform C++ serial communication library developed for Windows and Windows CE platforms. The library provides an easy-to-use API with support for multi-threading, asynchronous IO, buffer management, and other advanced features.

## Features

### Core Features
- **Cross-platform Support**: Windows (98/NT/2000/XP/Vista/7/8/10/11) and Windows CE 5.0
- **Multi-compiler Support**: VC++ 6~2022, C++ Builder 4~12, GCC/G++ 3~13, Intel C++ 7~2024, EVC 4
- **ANSI/UNICODE Support**: Full character set support
- **Hardware Compatibility**: PC serial ports, serial servers, USB serial ports, virtual serial ports

### Advanced Features
- **Multi-threading Support**: Built-in monitoring thread, read thread, write thread
- **Asynchronous IO**: Overlapped IO mode support (Windows)
- **Buffer Management**: Configurable read/write buffers
- **Message Notification**: Windows message mechanism for serial port events
- **Exception Handling**: Standard C++ exceptions, MFC exceptions, VCL exceptions
- **Flexible Configuration**: Rich option enumeration with runtime configuration support

### Main Classes and Components
- **CnComm**: Core serial communication class
- **BlockBuffer**: Memory block buffer management class
- **InnerLock**: Critical section lock class

## Installation and Usage

### Integration

CnComm is a header-only library. Simply include the header file:

```cpp
#include "CnComm.h"
```

### Compilation Options

Define the following macros before including the header to enable specific features:

```cpp
// Enable standard C++ exceptions
#define CN_COMM_STD_EXCEPTION

// Enable MFC exceptions (VC++ only)
#define CN_COMM_MFC_EXCEPTION

// Enable VCL exceptions (C++ Builder only)
#define CN_COMM_VCL_EXCEPTION

// Custom buffer block size (default 1024)
#define CN_COMM_BUFFER_MIN_BLOCK_SIZE 512

// Custom message base value
#define ON_COM_MSG_BASE WM_USER + 1000
```

### Basic Usage Examples

#### Example 1: Simple Serial Communication

```cpp
#include "CnComm.h"

// Simple serial communication example
void SayHello(DWORD dwPort)
{
    CnComm Com(0); // Non-blocking IO, no thread mode
    Com.Open(dwPort);
    Com.Write(_T("Hello World!"));
}

// Example with receive callback
class HelloComm : public CnComm
{
protected:
    void OnReceive()
    {
        TCHAR buffer[1024];
        _tprintf(_T("\nReceived: %s\n"), ReadString(buffer, 1024));
    }
};

int main()
{
    HelloComm Com; // Default mode: callback IO, monitoring thread
    Com.Open(2, 9600); // Open COM2, baud rate 9600
    
    system("pause");
    SayHello(1); // Send data to COM1
    system("pause");
    
    return 0;
}
```

#### Example 2: Using Buffers and Exception Handling

```cpp
#define CN_COMM_STD_EXCEPTION
#define CN_COMM_BUFFER_MIN_BLOCK_SIZE 512

#include "CnComm.h"

void TestException()
{
    try
    {
        CnComm Com;
        Com.Open(888); // Try to open non-existent port
    }
    catch (std::exception& e)
    {
        printf("Error: %s", e.what());
    }
}

void TestBlockBuffer()
{
    char buf[1024] = {0};
    CnComm::BlockBuffer bb;
    
    bb.Write("0123456789"); // Write 10 bytes
    bb.Read(buf, 5); // Read 5 bytes
    bb.Clear(); // Clear buffer
    printf("%s\n", buf); // Output: 01234
    
    // Get free pointer and write directly
    char *pFree = (char*)bb.GetFreePtr(10);
    strcpy(pFree, "0123456789");
    bb.Release(10); // Release 10 bytes
    
    // Copy data
    bb.Copy(buf, 5, 0); // Copy 5 bytes from offset 0
    printf("%s\n", buf); // Output: 01234
    
    bb.Read(NULL, 10); // Delete 10 bytes
}
```

#### Example 3: Advanced Configuration

```cpp
#include "CnComm.h"

int main()
{
    // Create serial port object with monitoring thread and async IO
    CnComm Com(CnComm::EN_THREAD | CnComm::EN_OVERLAPPED);
    
    // Configure serial port parameters
    Com.SetWaitEvent(EV_RXCHAR | EV_ERR | EV_CTS);
    Com.SetNotifyNum(1); // Notify on 1 byte received
    
    // Open serial port
    if (Com.Open(1, 9600, NOPARITY, 8, ONESTOPBIT))
    {
        // Set window handle for message notification
        // Com.SetWnd(hWnd);
        
        // Send data
        Com.Write("AT+RST\r\n");
        
        // Read data
        char response[256];
        Com.ReadString(response, sizeof(response));
        
        // Close serial port
        Com.Close();
    }
    
    return 0;
}
```

## API Reference

### CnComm Class

#### Constructors and Destructor

```cpp
// Default constructor
CnComm(DWORD dwOption = EN_THREAD | EN_OVERLAPPED);

// Legacy constructor for backward compatibility
CnComm(bool bThread, bool bOverlapped);

// Destructor
virtual ~CnComm();
```

#### Open and Close Serial Port

```cpp
// Open serial port (without configuration)
bool Open(DWORD dwPort);

// Open serial port with configuration
bool Open(DWORD dwPort, DWORD dwBaudRate, BYTE btParity = NOPARITY, 
          BYTE btByteSize = 8, BYTE btStopBits = ONESTOPBIT);

// Open serial port with string configuration (e.g., "9600,N,8,1")
bool Open(DWORD dwPort, LPCTSTR szSetStr);

// Open serial port with custom port name
bool Open(DWORD dwPort, LPCTSTR szPortName, DWORD dwBaudRate, 
          BYTE btParity = NOPARITY, BYTE btByteSize = 8, BYTE btStopBits = ONESTOPBIT);

// Close serial port
void Close();
```

#### Read and Write Operations

```cpp
// Read data
DWORD Read(LPVOID pBuffer, DWORD dwLength, DWORD dwWaitTime = INFINITE);

// Read string (ANSI)
char* ReadString(char *szBuffer, DWORD dwLength, DWORD dwWaitTime = INFINITE);

// Read string (UNICODE)
wchar_t* ReadString(wchar_t *szBuffer, DWORD dwLength, DWORD dwWaitTime = INFINITE);

// Write data
DWORD Write(LPCVOID pBuffer, DWORD dwLength);

// Write string
DWORD Write(const char *szBuffer);
DWORD Write(const wchar_t *szBuffer);

// Formatted write
DWORD Write(char *szBuffer, DWORD dwLength, char *szFormat, ...);
```

#### Status Queries

```cpp
// Check if serial port is open
bool IsOpen();

// Get serial port handle
HANDLE GetHandle();

// Get serial port number
DWORD GetPort();

// Get serial port name
LPCTSTR GetPortName();

// Get configuration options
DWORD GetOption();

// Set configuration options (when port is closed)
void SetOption(DWORD dwOption);
```

#### Thread Control

```cpp
// Start thread
bool BeginThread(DWORD dwThreadOption = 0);

// Suspend thread
bool SuspendThread(int iOption = EN_THREAD);

// Resume thread
bool ResumeThread(int iOption = EN_THREAD);

// Terminate thread
bool EndThread(DWORD dwWaitTime = 500);

// Get thread handle
HANDLE GetThread(int iOption = EN_THREAD);
```

#### Buffer Operations

```cpp
// Get input buffer
BlockBuffer& Input();

// Get output buffer
BlockBuffer& Output();

// Flush serial port
void FlushPort();

// Flush all data
void Flush();
```

#### Event Notification

```cpp
// Set notification window
void SetWnd(HWND hWnd);

// Set notification thread ID
void SetNotifyThreadId(DWORD dwId);

// Set notification byte count
void SetNotifyNum(DWORD dwNum);

// Set wait events
void SetWaitEvent(DWORD dwEvent = CN_COMM_WAIT_EVENT);
```

### BlockBuffer Class

```cpp
// Write data
DWORD Write(LPCVOID pData, DWORD dwLength);
DWORD Write(const char* lpBuf);      // Write ANSI string
DWORD Write(const wchar_t* lpBuf);   // Write UNICODE string

// Thread-safe write
DWORD SafeWrite(LPCVOID lpBuf, DWORD dwSize);
DWORD SafeWrite(const char* lpBuf);
DWORD SafeWrite(const wchar_t* lpBuf);

// Read data
DWORD Read(LPVOID pData, DWORD dwLength);

// Thread-safe read
DWORD SafeRead(LPVOID lpBuf, DWORD dwSize);

// Read string
char* ReadString(char* lpBuf, DWORD dMaxSize);
wchar_t* ReadString(wchar_t* lpBuf, DWORD dMaxSize);

// Thread-safe read string
char* SafeReadString(char* lpBuf, DWORD dMaxSize);
wchar_t* SafeReadString(wchar_t* lpBuf, DWORD dMaxSize);

// Copy data
DWORD Copy(LPVOID lpBuf, DWORD dwSize, DWORD dwStart = 0);

// Thread-safe copy
DWORD SafeCopy(LPVOID lpBuf, DWORD dwSize, DWORD dwStart = 0);

// Get free pointer
LPVOID GetFreePtr(DWORD dwSize = 0);

// Release space
void Release(DWORD dwSize);

// Clear buffer
void Clear(bool bDeleteAll = false);

// Thread-safe clear
void SafeClear(bool bDeleteAll = false);

// Get data size
DWORD Size();

// Thread-safe get size
DWORD SafeSize();

// Get free space size
DWORD FreeSize();

// Iterator
Iterator Begin();
```

### Option Enumeration (OptionEnum)

```cpp
enum OptionEnum
{
    EN_THREAD        = 0x00000001, // Enable monitoring thread
    EN_OVERLAPPED    = 0x00000002, // Enable async overlapped IO
    EN_RX_BUFFER     = 0x00000004, // Enable receive buffer
    EN_TX_BUFFER     = 0x00000008, // Enable transmit buffer
    EN_RX_THREAD     = 0x00000010, // Enable read thread
    EN_TX_THREAD     = 0x00000020, // Enable write thread
    EN_SUSPEND       = 0x00000040, // Suspend thread on start
    EN_ABOVE_NORMAL  = 0x00000080, // Increase thread priority
    EN_FLUSH         = 0x00000100, // Flush buffer on close
    EN_FLUSH_ALL     = 0x00000200  // Flush all buffers simultaneously
};
```

### Message Constants

```cpp
#define ON_COM_RECEIVE   ON_COM_MSG_BASE + 0   // Data received (EV_RXCHAR)
#define ON_COM_RXCHAR    ON_COM_MSG_BASE + 0   // Data received (alias)
#define ON_COM_CTS       ON_COM_MSG_BASE + 1   // CTS signal change
#define ON_COM_DSR       ON_COM_MSG_BASE + 2   // DSR signal change
#define ON_COM_RING      ON_COM_MSG_BASE + 3   // Ring signal
#define ON_COM_RLSD      ON_COM_MSG_BASE + 4   // RLSD signal change
#define ON_COM_BREAK     ON_COM_MSG_BASE + 5   // Break signal
#define ON_COM_TXEMPTY   ON_COM_MSG_BASE + 6   // Transmit buffer empty
#define ON_COM_ERROR     ON_COM_MSG_BASE + 7   // Error event
#define ON_COM_RXFLAG    ON_COM_MSG_BASE + 8   // Receive flag
#define ON_COM_POWER     ON_COM_MSG_BASE + 9   // Power event
#define ON_COM_EVENT1    ON_COM_MSG_BASE + 10  // Event 1
#define ON_COM_EVENT2    ON_COM_MSG_BASE + 11  // Event 2
#define ON_COM_RX80FULL  ON_COM_MSG_BASE + 12  // Receive buffer 80% full
#define ON_COM_PERR      ON_COM_MSG_BASE + 13  // Print error
```

## Compiler Compatibility

| Compiler | Version | Status |
|----------|---------|--------|
| Visual C++ | 6.0, .NET, 2003, 2005, 2008, 2010, 2012, 2013, 2015, 2017, 2019, 2022 | ✓ Fully Supported |
| C++ Builder | 4, 5, 6, X, 10, 11, 12 | ✓ Fully Supported |
| Borland C++ | 5.0 (Free Tool) | ✓ Fully Supported |
| GCC/G++ | 3.x, 4.x, 5.x, 6.x, 7.x, 8.x, 9.x, 10.x, 11.x, 12.x, 13.x | ✓ Fully Supported |
| Intel C++ | 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 2021, 2022, 2023, 2024 | ✓ Fully Supported |
| EVC | 4.0 (SP4) | ✓ Fully Supported (Windows CE) |

## Platform Support

| Platform | Version | Status |
|----------|---------|--------|
| Windows | 98, NT, 2000, XP, Vista, 7, 8, 10, 11 | ✓ Fully Supported |
| Windows CE | 5.0 | ✓ Fully Supported |
| Pocket PC | 2003 | ✓ Fully Supported |

## Contributing

### How to Contribute

1. **Fork the Project**: Click the Fork button at the top right of the project page
2. **Clone the Repository**: `git clone https://github.com/your-username/CnComm.git`
3. **Create a Branch**: `git checkout -b feature/your-feature`
4. **Commit Changes**: `git commit -m "Add your feature"`
5. **Push Branch**: `git push origin feature/your-feature`
6. **Create Pull Request**: Create a PR on GitHub

### Code Guidelines

- Follow existing code style
- Add necessary comments (Chinese or English)
- Ensure code compiles on all supported platforms
- Update relevant documentation

### Reporting Issues

Use GitHub Issues to report problems. Please include:

- Operating system and version
- Compiler and version
- Problem description and reproduction steps
- Relevant code snippets

### Development Environment

- Windows 7/8/10/11
- Visual Studio 2005 or later (recommended 2015+)
- Or other supported compilers (see compiler compatibility table)

## Version History

### v1.53 (2026.06)
- Fixed OnRLSD() sending wrong message constant (MS_RLSD_ON → ON_COM_RLSD)
- Fixed WriteModel() resetting wrong event handle (hWatchEvent_ → hWriteEvent_)
- Fixed BeginThread() checking wrong thread ID variable
- Fixed ReadString() integer underflow when dwLength==0
- Fixed fprintf format string vulnerability
- Replaced vsprintf with _vsnprintf to prevent buffer overflow
- Added parentheses to all message macros to prevent operator precedence errors
- Improved README documentation

### v1.52 (2018.12)
- Fixed timeout and efficiency issues when using Read function with synchronous+callback IO
- Fixed inconsistent comments in BlockBuffer's Clear function
- Fixed issue where bDeleteAll was not being used

### v1.51 (2009)
- Fixed memory management issues
- Optimized multi-threading performance

### v1.5 (2009)
- Improved separation of synchronous and asynchronous functionality
- Added Windows CE support

### v1.4 (2008)
- Added multi-threading support for synchronous IO
- Added C++ exception support
- Renamed to CnComm (C Next Communication)

### v1.3 (2007)
- Bug fixes and improvements

### v1.2 (2006)
- Bug fixes and improvements

### v1.1 (2005)
- Bug fixes and improvements

### v1.0 (2004)
- Initial release
- Based on VC class library
- Windows serial port communication support

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Authors

- **Original Author**: llbird (wushaojian@21cn.com)
  - Blog: http://blog.csdn.net/wujian53, http://www.cppblog.com/llbird
  - Maintenance Period: 2002.10 - 2009.8

- **Maintainer**: zzlhyly (huiyeluanyue@163.com)
  - Maintenance Period: 2018.12 - Present

## Acknowledgments

Thanks to all developers and users who have contributed to the CnComm project!

---

**Note**: Please retain the original copyright notice when using this library. It is recommended to extend functionality through C++ inheritance rather than directly modifying the source code.