# CnComm - C++ 串口通信库

[English](README_EN.md) | 中文

CnComm 是一个国人开发的跨平台 C++ 串口通信类库，支持 Windows 和 Windows CE 平台。该库提供了简单易用的 API，支持多线程、异步 IO、缓冲区管理等高级功能。

## 功能特性

### 核心功能
- **跨平台支持**：Windows (98/NT/2000/XP/Vista/7/8/10/11) 和 Windows CE 5.0
- **多编译器支持**：VC++ 6~2022, C++ Builder 4~12, GCC/G++ 3~13, Intel C++ 7~2024, EVC 4
- **ANSI/UNICODE 支持**：完整的字符集支持
- **硬件兼容**：PC 串口、串口服务器、USB 串口、虚拟串口

### 高级功能
- **多线程支持**：内置监控线程、读取线程、写入线程
- **异步 IO**：支持重叠 IO 模式（Windows）
- **缓冲区管理**：可配置的读写缓冲区
- **消息通知**：Windows 消息机制通知串口事件
- **异常处理**：支持标准 C++ 异常、MFC 异常、VCL 异常
- **灵活配置**：丰富的选项枚举，支持运行时配置

### 主要类和组件
- **CnComm**：核心串口通信类
- **BlockBuffer**：内存块缓冲区管理类
- **InnerLock**：临界区锁类

## 安装和使用

### 集成到项目

CnComm 是一个头文件库（Header-only），只需包含头文件即可使用：

```cpp
#include "CnComm.h"
```

### 编译选项

在包含头文件前定义以下宏来启用特定功能：

```cpp
// 启用标准 C++ 异常
#define CN_COMM_STD_EXCEPTION

// 启用 MFC 异常（仅 VC++）
#define CN_COMM_MFC_EXCEPTION

// 启用 VCL 异常（仅 C++ Builder）
#define CN_COMM_VCL_EXCEPTION

// 自定义缓冲区块大小（默认 1024）
#define CN_COMM_BUFFER_MIN_BLOCK_SIZE 512

// 自定义消息基础值
#define ON_COM_MSG_BASE WM_USER + 1000
```

### 基本使用示例

#### 示例 1：简单串口通信

```cpp
#include "CnComm.h"

// 简单的串口通信示例
void SayHello(DWORD dwPort)
{
    CnComm Com(0); // 非阻塞 IO，无线程模式
    Com.Open(dwPort);
    Com.Write(_T("Hello World!"));
}

// 带接收回调的示例
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
    HelloComm Com; // 默认模式：回调 IO，监控线程
    Com.Open(2, 9600); // 打开 COM2，波特率 9600
    
    system("pause");
    SayHello(1); // 向 COM1 发送数据
    system("pause");
    
    return 0;
}
```

#### 示例 2：使用缓冲区和异常处理

```cpp
#define CN_COMM_STD_EXCEPTION
#define CN_COMM_BUFFER_MIN_BLOCK_SIZE 512

#include "CnComm.h"

void TestException()
{
    try
    {
        CnComm Com;
        Com.Open(888); // 尝试打开不存在的端口
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
    
    bb.Write("0123456789"); // 写入 10 字节
    bb.Read(buf, 5); // 读取 5 字节
    bb.Clear(); // 清空缓冲区
    printf("%s\n", buf); // 输出: 01234
    
    // 获取空闲指针并直接写入
    char *pFree = (char*)bb.GetFreePtr(10);
    strcpy(pFree, "0123456789");
    bb.Release(10); // 释放 10 字节
    
    // 复制数据
    bb.Copy(buf, 5, 0); // 从偏移 0 处复制 5 字节
    printf("%s\n", buf); // 输出: 01234
    
    bb.Read(NULL, 10); // 删除 10 字节
}
```

#### 示例 3：高级配置

```cpp
#include "CnComm.h"

int main()
{
    // 创建串口对象，启用监控线程和异步 IO
    CnComm Com(CnComm::EN_THREAD | CnComm::EN_OVERLAPPED);
    
    // 配置串口参数
    Com.SetWaitEvent(EV_RXCHAR | EV_ERR | EV_CTS);
    Com.SetNotifyNum(1); // 收到 1 字节即通知
    
    // 打开串口
    if (Com.Open(1, 9600, NOPARITY, 8, ONESTOPBIT))
    {
        // 设置窗口句柄接收消息
        // Com.SetWnd(hWnd);
        
        // 发送数据
        Com.Write("AT+RST\r\n");
        
        // 读取数据
        char response[256];
        Com.ReadString(response, sizeof(response));
        
        // 关闭串口
        Com.Close();
    }
    
    return 0;
}
```

## API 参考

### CnComm 类

#### 构造函数和析构函数

```cpp
// 默认构造函数
CnComm(DWORD dwOption = EN_THREAD | EN_OVERLAPPED);

// 兼容旧版本的构造函数
CnComm(bool bThread, bool bOverlapped);

// 析构函数
virtual ~CnComm();
```

#### 打开和关闭串口

```cpp
// 打开串口（仅打开，不配置参数）
bool Open(DWORD dwPort);

// 打开串口并配置参数
bool Open(DWORD dwPort, DWORD dwBaudRate, BYTE btParity = NOPARITY, 
          BYTE btByteSize = 8, BYTE btStopBits = ONESTOPBIT);

// 使用字符串配置打开串口（如 "9600,N,8,1"）
bool Open(DWORD dwPort, LPCTSTR szSetStr);

// 使用自定义端口名打开串口
bool Open(DWORD dwPort, LPCTSTR szPortName, DWORD dwBaudRate, 
          BYTE btParity = NOPARITY, BYTE btByteSize = 8, BYTE btStopBits = ONESTOPBIT);

// 关闭串口
void Close();
```

#### 读写操作

```cpp
// 读取数据
DWORD Read(LPVOID pBuffer, DWORD dwLength, DWORD dwWaitTime = INFINITE);

// 读取字符串（ANSI）
char* ReadString(char *szBuffer, DWORD dwLength, DWORD dwWaitTime = INFINITE);

// 读取字符串（UNICODE）
wchar_t* ReadString(wchar_t *szBuffer, DWORD dwLength, DWORD dwWaitTime = INFINITE);

// 写入数据
DWORD Write(LPCVOID pBuffer, DWORD dwLength);

// 写入字符串
DWORD Write(const char *szBuffer);
DWORD Write(const wchar_t *szBuffer);

// 格式化写入
DWORD Write(char *szBuffer, DWORD dwLength, char *szFormat, ...);
```

#### 状态查询

```cpp
// 检查串口是否打开
bool IsOpen();

// 获取串口句柄
HANDLE GetHandle();

// 获取串口号
DWORD GetPort();

// 获取串口名称
LPCTSTR GetPortName();

// 获取配置选项
DWORD GetOption();

// 设置配置选项（串口关闭时）
void SetOption(DWORD dwOption);
```

#### 线程控制

```cpp
// 启动线程
bool BeginThread(DWORD dwThreadOption = 0);

// 挂起线程
bool SuspendThread(int iOption = EN_THREAD);

// 恢复线程
bool ResumeThread(int iOption = EN_THREAD);

// 终止线程
bool EndThread(DWORD dwWaitTime = 500);

// 获取线程句柄
HANDLE GetThread(int iOption = EN_THREAD);
```

#### 缓冲区操作

```cpp
// 获取输入缓冲区
BlockBuffer& Input();

// 获取输出缓冲区
BlockBuffer& Output();

// 刷新串口
void FlushPort();

// 刷新所有数据
void Flush();
```

#### 事件通知

```cpp
// 设置通知窗口
void SetWnd(HWND hWnd);

// 设置通知线程 ID
void SetNotifyThreadId(DWORD dwId);

// 设置通知字节数
void SetNotifyNum(DWORD dwNum);

// 设置等待事件
void SetWaitEvent(DWORD dwEvent = CN_COMM_WAIT_EVENT);
```

### BlockBuffer 类

```cpp
// 写入数据
DWORD Write(LPCVOID pData, DWORD dwLength);
DWORD Write(const char* lpBuf);      // 写入 ANSI 字符串
DWORD Write(const wchar_t* lpBuf);   // 写入 UNICODE 字符串

// 线程安全写入
DWORD SafeWrite(LPCVOID lpBuf, DWORD dwSize);
DWORD SafeWrite(const char* lpBuf);
DWORD SafeWrite(const wchar_t* lpBuf);

// 读取数据
DWORD Read(LPVOID pData, DWORD dwLength);

// 线程安全读取
DWORD SafeRead(LPVOID lpBuf, DWORD dwSize);

// 读取字符串
char* ReadString(char* lpBuf, DWORD dMaxSize);
wchar_t* ReadString(wchar_t* lpBuf, DWORD dMaxSize);

// 线程安全读取字符串
char* SafeReadString(char* lpBuf, DWORD dMaxSize);
wchar_t* SafeReadString(wchar_t* lpBuf, DWORD dMaxSize);

// 复制数据
DWORD Copy(LPVOID lpBuf, DWORD dwSize, DWORD dwStart = 0);

// 线程安全复制
DWORD SafeCopy(LPVOID lpBuf, DWORD dwSize, DWORD dwStart = 0);

// 获取空闲指针
LPVOID GetFreePtr(DWORD dwSize = 0);

// 释放空间
void Release(DWORD dwSize);

// 清空缓冲区
void Clear(bool bDeleteAll = false);

// 线程安全清空
void SafeClear(bool bDeleteAll = false);

// 获取数据大小
DWORD Size();

// 线程安全获取大小
DWORD SafeSize();

// 获取空闲空间大小
DWORD FreeSize();

// 迭代器
Iterator Begin();
```

### 选项枚举 (OptionEnum)

```cpp
enum OptionEnum
{
    EN_THREAD        = 0x00000001, // 启用监控线程
    EN_OVERLAPPED    = 0x00000002, // 启用异步重叠 IO
    EN_RX_BUFFER     = 0x00000004, // 启用接收缓冲区
    EN_TX_BUFFER     = 0x00000008, // 启用发送缓冲区
    EN_RX_THREAD     = 0x00000010, // 启用读取线程
    EN_TX_THREAD     = 0x00000020, // 启用写入线程
    EN_SUSPEND       = 0x00000040, // 线程启动时暂停
    EN_ABOVE_NORMAL  = 0x00000080, // 提高线程优先级
    EN_FLUSH         = 0x00000100, // 关闭时刷新缓冲区
    EN_FLUSH_ALL     = 0x00000200  // 同时刷新所有缓冲区
};
```

### 消息常量

```cpp
#define ON_COM_RECEIVE   ON_COM_MSG_BASE + 0   // 接收数据 (EV_RXCHAR)
#define ON_COM_RXCHAR    ON_COM_MSG_BASE + 0   // 接收数据 (别名)
#define ON_COM_CTS       ON_COM_MSG_BASE + 1   // CTS 信号变化
#define ON_COM_DSR       ON_COM_MSG_BASE + 2   // DSR 信号变化
#define ON_COM_RING      ON_COM_MSG_BASE + 3   // 振铃信号
#define ON_COM_RLSD      ON_COM_MSG_BASE + 4   // RLSD 信号变化
#define ON_COM_BREAK     ON_COM_MSG_BASE + 5   // 中断信号
#define ON_COM_TXEMPTY   ON_COM_MSG_BASE + 6   // 发送缓冲区空
#define ON_COM_ERROR     ON_COM_MSG_BASE + 7   // 错误事件
#define ON_COM_RXFLAG    ON_COM_MSG_BASE + 8   // 接收标志
#define ON_COM_POWER     ON_COM_MSG_BASE + 9   // 电源事件
#define ON_COM_EVENT1    ON_COM_MSG_BASE + 10  // 事件1
#define ON_COM_EVENT2    ON_COM_MSG_BASE + 11  // 事件2
#define ON_COM_RX80FULL  ON_COM_MSG_BASE + 12  // 接收缓冲区80%满
#define ON_COM_PERR      ON_COM_MSG_BASE + 13  // 打印错误
```

## 编译器兼容性

| 编译器 | 版本 | 状态 |
|--------|------|------|
| Visual C++ | 6.0, .NET, 2003, 2005, 2008, 2010, 2012, 2013, 2015, 2017, 2019, 2022 | ✓ 完全支持 |
| C++ Builder | 4, 5, 6, X, 10, 11, 12 | ✓ 完全支持 |
| Borland C++ | 5.0 (Free Tool) | ✓ 完全支持 |
| GCC/G++ | 3.x, 4.x, 5.x, 6.x, 7.x, 8.x, 9.x, 10.x, 11.x, 12.x, 13.x | ✓ 完全支持 |
| Intel C++ | 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 2021, 2022, 2023, 2024 | ✓ 完全支持 |
| EVC | 4.0 (SP4) | ✓ 完全支持（Windows CE） |

## 平台支持

| 平台 | 版本 | 状态 |
|------|------|------|
| Windows | 98, NT, 2000, XP, Vista, 7, 8, 10, 11 | ✓ 完全支持 |
| Windows CE | 5.0 | ✓ 完全支持 |
| Pocket PC | 2003 | ✓ 完全支持 |

## 贡献指南

### 如何贡献

1. **Fork 项目**：点击项目右上角的 Fork 按钮
2. **克隆仓库**：`git clone https://github.com/your-username/CnComm.git`
3. **创建分支**：`git checkout -b feature/your-feature`
4. **提交更改**：`git commit -m "Add your feature"`
5. **推送分支**：`git push origin feature/your-feature`
6. **创建 Pull Request**：在 GitHub 上创建 PR

### 代码规范

- 遵循现有的代码风格
- 添加必要的注释（中英文均可）
- 确保代码在所有支持的平台上编译通过
- 更新相关文档

### 报告问题

使用 GitHub Issues 报告问题，请包含：

- 操作系统和版本
- 编译器和版本
- 问题描述和重现步骤
- 相关代码片段

### 开发环境

- Windows 7/8/10/11
- Visual Studio 2005 或更高版本（推荐 2015+）
- 或其他支持的编译器（见编译器兼容性表格）

## 版本历史

### v1.53 (2026.06)
- 修复 OnRLSD() 发送错误消息常量 (MS_RLSD_ON → ON_COM_RLSD)
- 修复 WriteModel() 重置错误事件句柄 (hWatchEvent_ → hWriteEvent_)
- 修复 BeginThread() 检查错误的线程ID变量
- 修复 ReadString() 当 dwLength==0 时的整数下溢问题
- 修复 fprintf 格式字符串漏洞
- 替换 vsprintf 为 _vsnprintf 防止缓冲区溢出
- 给所有消息宏添加括号防止运算符优先级错误
- 完善 README 文档

### v1.52 (2018.12)
- 修复同步+回调 IO 时使用 Read 函数读取数据的超时及效率问题
- 修复 BlockBuffer 的 Clear 函数注释不一致问题
- 修复 bDeleteAll 没有被使用的问题

### v1.51 (2009)
- 修复内存管理问题
- 优化多线程性能

### v1.5 (2009)
- 完善同步和异步功能分离
- 增加对 Windows CE 的支持

### v1.4 (2008)
- 增加对同步 IO 的多线程支持
- 增加 C++ 异常支持
- 更名为 CnComm (C Next Communication)

### v1.3 (2007)
- 细节修复和完善

### v1.2 (2006)
- 细节修复和完善

### v1.1 (2005)
- 细节修复和完善

### v1.0 (2004)
- 首次发布
- 基于 VC 类库开发
- 支持 Windows 平台串口通信

## 许可证

本项目基于 MIT 许可证开源 - 详见 [LICENSE](LICENSE) 文件

## 作者

- **原作者**：llbird (wushaojian@21cn.com)
  - 博客：http://blog.csdn.net/wujian53, http://www.cppblog.com/llbird
  - 维护时间：2002.10 - 2009.8

- **维护者**：zzlhyly (huiyeluanyue@163.com)
  - 维护时间：2018.12 - 至今

## 致谢

感谢所有为 CnComm 项目做出贡献的开发者和用户！

---

**注意**：使用本库时请保留原始版权声明。鼓励通过 C++ 继承机制扩展功能，而非直接修改源代码。