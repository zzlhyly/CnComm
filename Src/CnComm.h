// ������ԭ��˵��
/*! \mainpage CnComm v1.51 ���̴߳���ͨѶ�� 
 *	\section About ����
 *  
 *  \n �汾: CnComm v1.51
 *  \n ��;: WINDOWS/WINCE ���̴߳���ͨѶ��
 *  \n ����: C++ (ANSI/UNICODE)
 *  \n ƽ̨: WINDOWS(WIN98/NT/2000/XP/2003/Vista); WINCE 5.0 ģ����; Pocket PC 2003 ģ����;
 *  \n Ӳ��: PC����; ���ڷ�����; USB����; ���⴮��;
 *  \n ����: BC++ 5(free tool); C++ BUILDER 4, 5, 6, X; EVC 4(sp4); G++ 3, 4; Intel C++ 7, 8, 9; VC++ 6(sp6), .NET, 2003, 2005;
 *  \n ����: llbird
 *  \n ����: wushaojian@21cn.com
 *  \n ����: http://blog.csdn.net/wujian53 http://www.cppblog.com/llbird  
 *  \n ά��: 2002.10 - 2009.8
 *
 *  \section Announce ˵��
 *  \n 1) ��������ʹ�ü�����, �뱣���������;                                           
 *  \n 2) ���Ƽ�ֱ���ڱ��������޸�, Ӧͨ��C++�̳���չ������չ������;                          
 *  \n 3) �����ֱ���޸ı�����, �뷢һ�ݸ��ң�����ͬ���ѷ���������ĸĶ�;                              
 *  \n 4) ������cnComm1.4���°汾, �кܴ�Ķ���ͬʱҲ����CnComm;
 *  \n 5) �����Ǿ��ϻ�, ˮƽ����, ������������, ��ӭ����ָ��, ��������, ʱ������, ���ṩ��CnComm�ڲ����������ѯ;
 *  
 *  \section Log ��־
 *  \n 2009 v1.51 ������; ���ǵ������Ĺ����п��ܲ����ٺʹ��ڴ򽻵�����ܿ��������һ��;
 *  \n 2009 v1.5  �������÷ֿ�����������; ���Ӷ�WINCE��֧��(ģ�����²���ͨ��);
 *  \n 2008 v1.4  ���Ӷ�ͬ��IO�Ķ��߳�֧��; ����C++�쳣��֧��; ����CnComm; Cn == C Next;
 *  \n 2007 v1.3  ϸ�ڲ����޶�;
 *  \n 2006 v1.2  ϸ�ڲ����޶�;
 *  \n 2005 v1.1  ϸ�ڲ����޶�;
 *  \n 2004 v1.0  ����VC�������(������), �ڶ��WINDOWƽ̨������������ͨ��, �״ι�������cnComm;
 *  \n 2002 v0.1  ������Ҫ��������ͨѶ������, ��ͳC++�ļ̳л���, ��ͳC�������;
 */

// �����Ǳ��˵�˵��
/*! \mainpage CnComm v1.52 ���̴߳���ͨѶ�� 
 *	\section About ����
 *  
 *  \n �汾: CnComm v1.52
 *  \n ��;: WINDOWS/WINCE ���̴߳���ͨѶ��
 *  \n ����: C++ (ANSI/UNICODE)
 *  \n ƽ̨: WINDOWS(WIN98/NT/2000/XP/2003/Vista); WINCE 5.0 ģ����; Pocket PC 2003 ģ����;
 *  \n Ӳ��: PC����; ���ڷ�����; USB����; ���⴮��;
 *  \n ����: BC++ 5(free tool); C++ BUILDER 4, 5, 6, X; EVC 4(sp4); G++ 3, 4; Intel C++ 7, 8, 9; VC++ 6(sp6), .NET, 2003, 2005;
 *  \n ����: zzlhyly
 *  \n ����: huiyeluanyue@163.com
 *  \n ά��: 2018.12 -
 *
 *  \section Announce ˵��
 *  \n 1) ��������ʹ�ü�����, �뱣���������;                                           
 *  \n 2) ���Ƽ�ֱ���ڱ��������޸�, Ӧͨ��C++�̳���չ������չ������;                          
 *  \n 3) �����ֱ���޸ı�����, �뷢һ�ݸ��ң�����ͬ���ѷ���������ĸĶ�;                              
 *  \n 4) ������cnComm1.4���°汾, �кܴ�Ķ���ͬʱҲ����CnComm;
 *  \n 5) �����Ǿ��ϻ�, ˮƽ����, ������������, ��ӭ����ָ��, ��������, ʱ������, ���ṩ��CnComm�ڲ����������ѯ;
 *  
 *  \section Log ��־
 *  \n 2018.12 v1.52 ����ͬ��+�ص�IOʱʹ��Read������ȡ���ݵĳ������󼰳�ʱ��Ч������
 					 ����BlockBuffer��Clear������ע�Ͳ�һ�������⣬��bDeleteAllû��ʹ�õ�����
 */


#ifndef _CN_COMM_H_
#define _CN_COMM_H_

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <tchar.h>

#if defined(UNDER_CE) && !defined(CN_COMM_FOR_CE)
	#define CN_COMM_FOR_CE		UNDER_CE			//!< ����WINCE��֧��   
#endif

#ifndef CN_COMM_FOR_CE
	#include <mcx.h>
	#include <process.h>							// WINCEû��process.h
#endif

#ifndef ON_COM_MSG_BASE 
	#define ON_COM_MSG_BASE		(WM_USER + 618)		//!< ��Ϣ��ŵĻ���  
#endif

// �͵����ڵ���Ϣ WPARAM COM�˿ں�
#define ON_COM_RECEIVE			(ON_COM_MSG_BASE + 0)	//!< EV_RXCHAR 
#define ON_COM_RXCHAR			(ON_COM_MSG_BASE + 0) //!< EV_RXCHAR 
#define ON_COM_CTS				(ON_COM_MSG_BASE + 1) //!< EV_CTS  LPARAM==1 CTS ON 
#define ON_COM_DSR				(ON_COM_MSG_BASE + 2) //!< EV_DSR  LPARAM==1 DSR ON
#define ON_COM_RING				(ON_COM_MSG_BASE + 3) //!< EV_RING LPARAM==1 RING ON
#define ON_COM_RLSD				(ON_COM_MSG_BASE + 4) //!< EV_RLSD LPARAM==1 RLSD ON
#define ON_COM_BREAK			(ON_COM_MSG_BASE + 5) //!< EV_BREAK
#define ON_COM_TXEMPTY			(ON_COM_MSG_BASE + 6) //!< EV_TXEMPTY 
#define ON_COM_ERROR			(ON_COM_MSG_BASE + 7) //!< EV_ERR  LPARAM Error ID 
#define ON_COM_RXFLAG			(ON_COM_MSG_BASE + 8) //!< EV_RXFLAG
#define ON_COM_POWER			(ON_COM_MSG_BASE + 9) //!< EV_POWER 
#define ON_COM_EVENT1			(ON_COM_MSG_BASE + 10)//!< EV_EVENT1
#define ON_COM_EVENT2			(ON_COM_MSG_BASE + 11)//!< EV_EVENT2 
#define ON_COM_RX80FULL			(ON_COM_MSG_BASE + 12)//!< EV_RX80FULL
#define ON_COM_PERR				(ON_COM_MSG_BASE + 13)//!< EV_PERR

#ifndef CN_COMM_WAIT_EVENT
	#ifdef CN_COMM_FOR_CE
		#define CN_COMM_WAIT_EVENT	(EV_RXCHAR | EV_ERR | EV_CTS | EV_DSR | EV_BREAK | EV_TXEMPTY | EV_RING | EV_RLSD | EV_POWER) //!< WINCE Ĭ�ϵĵȴ��¼�| EV_RXFLAG 
	#else
		#define CN_COMM_WAIT_EVENT	(EV_RXCHAR | EV_ERR | EV_CTS | EV_DSR | EV_BREAK | EV_TXEMPTY | EV_RING | EV_RLSD) 			//!< WIN32 Ĭ�ϵĵȴ��¼�| EV_RXFLAG
	#endif
#endif

#ifndef CN_COMM_BUFFER_MIN_BLOCK_SIZE
	#define CN_COMM_BUFFER_MIN_BLOCK_SIZE 1024		//!< ���建���������Сֵ 
#endif

#if CN_COMM_BUFFER_MIN_BLOCK_SIZE < 4
	#error CN_COMM_BUFFER_MIN_BLOCK_SIZE must >= 4	//!< �����������Сֵ������С��4 
#endif

#ifndef CN_ASSERT
	#define CN_2STR(x)		_T(#x)					//!< 将表达式x转换成字符串
	#define CN_LINE(line)	CN_2STR(line)			//!< 将行号line转换成字符串
	/*! 内部使用 断言或异常或抛出异常 或者可以关闭它 有不被断言异常处理的任何错误处理 */
	#define CN_ASSERT(E)	((E) ? true : CnComm::Assert(_T("CN_ASSERT(") _T(#E) _T(") failed; CnComm(") CN_LINE(__LINE__) _T("); ")))
#endif

//CN_COMM_STD_EXCEPTION CN_ASSERT ���׳���׼C++�쳣			
#ifdef CN_COMM_STD_EXCEPTION
	#include <stdexcept> //throw runtime_error(msg)
#endif

//CN_COMM_VCL_EXCEPTION CN_ASSERT ���׳�VCL�쳣(C++ Builder)	
#if defined(CN_COMM_VCL_EXCEPTION) && defined(__BORLANDC__)
	#include <vcl.h> //throw new Exception(msg)	
#endif

//CN_COMM_MFC_EXCEPTION CN_ASSERT ���׳�MFC�쳣(VC++)			
#ifdef CN_COMM_MFC_EXCEPTION
	#include <Afx.h> //throw new MfcException(msg)	
#endif

/*! \class CnComm 
	\version 1.5 
	\date 2002.10-2009.4
	\author llbird(wushaojian@21cn.com http://www.cppblog.com/llbird  http://blog.csdn.net/wujian53) 
	\brief WIN32/WINCE C++ (ANSI/UNICODE) ���̴߳���ͨѶ������  
	\example doc_0.cpp ����0 \example doc_1.cpp \example doc_2.cpp \example doc_3.cpp \example SerialDlg.cpp
 */
class CnComm    
{
public:
	//! �ٽ���
	struct	InnerLock;
	//! ��������
	class	BlockBuffer;	
	//! MFC�쳣
	class	MfcException;				
	//! ��������ģʽ��ö��ֵ, 32λ����
	enum OptionEnum
	{
		EN_THREAD		= 0x00000001,	//!< ���ü����߳� ���洮�ڴ����� WatchThread
		EN_OVERLAPPED	= 0x00000002,	//!< �����첽�ص�IO��ʽ 
		EN_RX_BUFFER	= 0x00000004,	//!< ���ö�����
		EN_TX_BUFFER	= 0x00000008,	//!< ����д����
		EN_RX_THREAD	= 0x00000010,	//!< �������߳� ��ʱδ�� ReadThread
		EN_TX_THREAD	= 0x00000020,	//!< ����д�߳� ����WINCE��˫������ Ӧͬʱ����д���� ���洮�ڴ����� WriteThread
		EN_SUSPEND		= 0x00000040,	//!< �����߳�ʱ��ͣ 
		EN_ABOVE_NORMAL	= 0x00000080,	//!< �����߳����ȼ���һ������
		EN_FLUSH		= 0x00000100,	//!< ���رմ���ʱ�������δ�����������(�˿ڻ�����) �������ȴ�                          
		EN_FLUSH_ALL	= 0x00000200	//!< ͬ��(����д���弰�˿ڶ���) �����������дģ�����û��д�� ���ܵ����̹߳����޷������ر� 
	};
	//! ���캯�� ���þ���Ӧ��ģʽ \param[in] dwOption ������Ҫ��OptionEnum��϶���
#ifdef CN_COMM_FOR_CE
	//! WINCE:Ĭ�ϴ򿪴���ʱ���������߳� ����д�����߳� ����д����
	CnComm(DWORD dwOption = EN_THREAD ) 
#else 
	//! WIN32:Ĭ�ϴ򿪴���ʱ���������߳� �첽�ص���ʽ 
	CnComm(DWORD dwOption = EN_THREAD | EN_OVERLAPPED)
#endif
	{
		Init(); 
		SetOption(dwOption);
	}
	//! ��һģʽ���� ����cnComm1~1.3 \param[in] bThread ���������߳� \param[in] bOverlapped �����ص�I/O
	CnComm(bool bThread, bool bOverlapped)
	{
		DWORD dwOption = 0;

		if (bThread)
			dwOption |= EN_THREAD;

		if (bOverlapped)
			dwOption |= EN_OVERLAPPED;

		Init(); 
		SetOption(dwOption);
	}
	//! ���� �Զ��رմ��� 
	virtual ~CnComm()
	{
		Close(); 
		Destroy();
	}
	//! �жϴ����ǻ��
	bool IsOpen()
	{
		return hComm_ != INVALID_HANDLE_VALUE;
	}
	//! �жϴ����ǻ��
	operator bool ()
	{
		return hComm_ != INVALID_HANDLE_VALUE;
	}
	//! ��ô��ھ��
	HANDLE GetHandle()
	{
		return hComm_;
	}
	//! ��ô��ھ��
	operator HANDLE()
	{
		return hComm_;
	}
	//! ��ô������
	DWORD GetPort()
	{
		return dwPort_;
	}
	//! ��ô���ȫ��
	LPCTSTR GetPortName()
	{
		return szName_;
	}
	//! ���CnComm�Ļ������ò��� ����32λ��������
	DWORD GetOption()
	{
		return dwOption_;
	}
	//! ����CnComm�Ļ������ò��� �ڴ򿪴���ǰ���������� \param[in] dwOption 32λ��������
	void SetOption(DWORD dwOption)
	{
		CN_ASSERT(!IsOpen());//! ��״̬�²��������ò���

		dwOption_ = dwOption;

	#ifdef CN_COMM_FOR_CE
		CN_ASSERT(!IsOverlappedMode()); //! WINCE������ʹ���ص�IO ��EN_OVERLAPPED����
		dwOption_ &= (~EN_OVERLAPPED);
	#endif
	}
	//! �޸�CnComm�Ļ������ò��� �ڴ򿪴���ǰ���������� \param[in] dwRemove ɾ����32λ�������� \param[in] dwAdd ���ӵ�32λ��������
	void ModifyOption(DWORD dwRemove, DWORD dwAdd)
	{
		CN_ASSERT(!IsOpen());//! ��״̬�²��������ò���

		dwOption_ &= ~dwRemove;
		dwOption_ |= dwAdd;

	#ifdef CN_COMM_FOR_CE
		CN_ASSERT(!IsOverlappedMode()); //! WINCE������ʹ���ص�IO ��EN_OVERLAPPED����
		dwOption_ &= (~EN_OVERLAPPED);
	#endif
	}
	//! �Ƿ��ص�IOģʽ
	bool IsOverlappedMode()
	{
		return dwOption_ & EN_OVERLAPPED ? true : false;
	}
	//! �Ƿ����������ģʽ
	bool IsTxBufferMode()
	{
		return dwOption_ & EN_TX_BUFFER ? true : false;
	}
	//! �Ƿ����뻺����ģʽ
	bool IsRxBufferMode()
	{
		return dwOption_ & EN_RX_BUFFER ? true : false;
	}
	//! ������Ϣ�Ĵ��ھ��
	void SetWnd(HWND hWnd)
	{
		CN_ASSERT(::IsWindow(hWnd));
		hNotifyWnd_ = hWnd;
	}
	//! ������Ϣ�Ĵ��ھ��
	HWND GetWnd()
	{
		return hNotifyWnd_;
	}
	//! ������Ϣ�Ĵ��ھ��
	void SetNotifyThreadId(DWORD dwId)
	{
		hNotifyThreadId_ = dwId;
	}
	//! ������Ϣ�Ĵ��ھ��
	DWORD GetNotifyThreadId()
	{
		return hNotifyThreadId_;
	}
	//! �趨����֪ͨ, �����ַ���Сֵ
	void SetNotifyNum(DWORD dwNum)
	{
		dwNotifyNum_ = dwNum;
	}
	//! ����߳̾�� \param[in] iOption EN_THREAD���hWatchThread_ EN_RX_THREAD���hReadThread_ EN_TX_THREAD���hWriteThread_ \return HANDLE �߳̾��
	HANDLE GetThread(int iOption = EN_THREAD)
	{
		return iOption == EN_THREAD ? hWatchThread_ : ((iOption == EN_RX_THREAD) ? hReadThread_ : hWriteThread_);
	}
	//! ����Ҫ���ӵ��¼��� ��ǰ������Ч
	void SetWaitEvent(DWORD dwEvent = CN_COMM_WAIT_EVENT)
	{
		CN_ASSERT(!IsOpen());///��״̬�²��������ò���

		dwWaitEvent_ = dwEvent;
	}
	//! ���뻺����
	BlockBuffer& Input()
	{
		return I_;
	}
	//! ���������
	BlockBuffer& Output()
	{
		return O_;
	}
	//! �����������ļ��� \param[in] bInput Ϊtrue����������,Ĭ��Ϊtrue �ص�IO������ǲ���ȷ�� ��Ϊ�����ϵͳ��̨���� ������ȫ��� 
	DWORD GetCounter(bool bInput = true)
	{
		return bInput ? dwInCount_ : dwOutCount_;
	}
	//! �����������������
	void ResetCounter()
	{
		dwInCount_ = dwOutCount_ = 0;
	}
	//! �򿪴��� ��ע����cnComm1~1.3������ cnComm1~1.3��ʹ��9600, n, 8, 1���ö˿� ��1.5��ֻ�򿪶˿ڲ����ò����ʵȲ���  \param[in] dwPort ������� 1~1024
	bool Open(DWORD dwPort)
	{
		if (!CN_ASSERT(dwPort>=1 && dwPort<=1024))
			return false;
		
		BindPort(dwPort);
		
		if(!CN_ASSERT(OpenPort()))
			return false;
		
		if(!CN_ASSERT(SetupPort()))
			return Close(), false;

		if ((dwOption_ & (EN_THREAD|EN_RX_THREAD|EN_TX_THREAD)) && !CN_ASSERT(BeginThread()))
			return Close(), false;

		return true;
	}
	/*! \param[in] dwPort ������� 1~1024 \param[in] dwBaudRate ������ \param[in] btParity  ��żУ�� \param[in] btByteSize ����λ��	\param[in] btStopBits ֹͣλ��	*/
	//! �򿪴��� ȱʡ 9600, n, 8, 1 \sa bool Open(DWORD dwPort, LPCTSTR szSetStr)
	bool Open(DWORD dwPort, DWORD dwBaudRate, BYTE btParity = NOPARITY, BYTE btByteSize = 8, BYTE btStopBits = ONESTOPBIT)
	{
		if (!CN_ASSERT(dwPort>=1 && dwPort<=1024))
			return false;
		
		BindPort(dwPort);
		
		if (!CN_ASSERT(OpenPort()))
			return false;
		
		if (!CN_ASSERT(SetState(dwBaudRate, btParity, btByteSize, btStopBits)))
			return Close(), false;

		if (!CN_ASSERT(SetupPort()))
			return Close(), false;

		if ((dwOption_ & (EN_THREAD|EN_RX_THREAD|EN_TX_THREAD)) && !CN_ASSERT(BeginThread()))
			return Close(), false;

		return true;
	}
#ifndef CN_COMM_FOR_CE
	/*! \param[in] dwPort ������� 1~1024 \param[in] szSetStr �ַ������� "BBBB,P,D,S"  ��: "9600,N,8,1"  "1200,O,7,2" 
		 BBBBΪ������ PΪ��żУ��(E | M | N | O | S) DΪ����λ��(4 ~ 8) SΪֹͣλ��(1 | 1.5 | 2)
		 \code Open(1, "9600,E,8,2"); \endcode  \b ��ע���ַ���������˳�� ����鷵��ֵ
		 ��֧��WINCE, ԭ�����Լ�д��һ���������, ���ǵ�WINCEӲ���ĸ�����, ��ֲ�Կ��ܲ���, �ʴ�����汾��ɾ����	*/
	//! �򿪴���, �ַ������ô���
	bool Open(DWORD dwPort, LPCTSTR szSetStr)
	{
		if (!CN_ASSERT(dwPort>=1 && dwPort<=1024))
			return false;
		
		BindPort(dwPort);
		
		if (!CN_ASSERT(OpenPort()))
			return false;
		
		if (!CN_ASSERT(SetState(szSetStr))) 
			return Close(), false;

		if (!CN_ASSERT(SetupPort()))
			return Close(), false;

		if ((dwOption_ & (EN_THREAD|EN_RX_THREAD|EN_TX_THREAD)) && !CN_ASSERT(BeginThread()))
			return Close(), false;
		
		return true;
	}
#endif
	/*! \param[in] dwPort ��ʱ�ò���û�о������壬��������Ϣ֪ͨ�б��˿ںţ�Ӧע�ⲻ�������˿ں��ظ� 
		\param[in] szPortName Ϊָ���Ķ˿�����, ����WINDOWS��\\\\.\\COM1����WINCE��COM1: , ��Щ���⴮�ڿ��������������
		\param[in] dwBaudRate ������	\param[in] btParity ��żУ��	\param[in] btByteSize ����λ��	\param[in] btStopBits ֹͣλ��
		\code Open(9999, "COM3:", 2400); \endcode 	\code Open(1028, "COM3:", 9600, N, 7, ONESTOPBIT); \endcode	*/
	//! ָ���Ķ˿����ƴ򿪴���
	bool Open(DWORD dwPort, LPCTSTR szPortName, DWORD dwBaudRate, BYTE btParity = NOPARITY, BYTE btByteSize = 8, BYTE btStopBits = ONESTOPBIT)
	{
		if(!CN_ASSERT(_tcslen(szPortName) < 64 - 1))
			return false;
		
		_tcscpy(szName_, szPortName);
		dwPort_ = dwPort;//����֪ͨ��Ϣ
		
		if (!CN_ASSERT(OpenPort()))
			return false;
		
		if (!CN_ASSERT(SetState(dwBaudRate, btParity, btByteSize, btStopBits)))
			return Close(), false;

		if (!CN_ASSERT(SetupPort()))
			return Close(), false;

		if ((dwOption_ & (EN_THREAD|EN_RX_THREAD|EN_TX_THREAD)) && !CN_ASSERT(BeginThread()))
			return Close(), false;
		
		return true;
	}
	//! ֱ�Ӷ������˿� \param[out] pBuffer Ŀ�껺���� \param[in] dwLength ��ȡ���� \param[in] dwWaitTime �ȴ�ʱ��(Ĭ��INFINITE) \return ����ʵ�ʶ�ȡ�ֽ���
	DWORD ReadPort(LPVOID pBuffer, DWORD dwLength, DWORD dwWaitTime = INFINITE)
	{
		COMSTAT Stat;
		DWORD	dwError, dwReadResult = 0;
		
		if(!CN_ASSERT(IsOpen()) || !dwLength)
			return 0;
		
		if(::ClearCommError(hComm_, &dwError, &Stat) && dwError > 0)
			::PurgeComm(hComm_, PURGE_RXABORT);

	#ifndef CN_COMM_FOR_CE
		if (IsOverlappedMode())//! �ص�I/O�� dwWaitTime==INFINITE ���ȴ�����Ȼ��ʱ��������� ����ʱ���ɳ�ʱ�ṹ���� Ĭ���趨0.5��
		{
			if (dwWaitTime == INFINITE)//! �����û�����ö����� ֱ�Ӷ�ȡ�˿ڽ��������� �൱��ԭ��1.3�汾 Read(pBuffer, dwLength, false);
			{
				if (!::ReadFile(hComm_, pBuffer, dwLength, &dwReadResult, &RO_))
				{//! �ڽ�����ʹ��CnComm�Ƽ�ʹ�ö�������������dwWaitTimeָ����ʱʱ��
					if (CN_ASSERT(::GetLastError() == ERROR_IO_PENDING))
					{
						while (!CN_ASSERT(::GetOverlappedResult(hComm_, &RO_, &dwReadResult, TRUE)))
							;
					}
				}
			}
			else//! �ص�I/O�� dwWaitTime!=INFINITE ���ȴ�����ʱ��������� ����ʱ����dwWaitTime���� 
			{	//! dwWaitTime = 0 �൱��ԭ��1.3�汾�Ĺ���
				DWORD dwBegin = GetTickCount(), dwEnd, dwCost, uReadLength, uReadReturn;
				
				uReadLength = Stat.cbInQue > dwLength ? dwLength : Stat.cbInQue;
				CN_ASSERT(::ReadFile(hComm_, pBuffer, uReadLength, &uReadReturn, &RO_));
				dwReadResult += uReadReturn;

				if (dwReadResult >= dwLength)
				{
					return dwInCount_ += dwReadResult, dwReadResult;
				}

				do
				{
					if (!::ReadFile(hComm_, (LPBYTE)pBuffer + dwReadResult, 1, &uReadReturn, &RO_))
					{
						if ((dwWaitTime != 0) && (WaitForSingleObject(RO_.hEvent, dwWaitTime) == WAIT_OBJECT_0))
						{
							dwEnd = GetTickCount();
							dwCost = dwEnd>=dwBegin ? dwEnd-dwBegin : DWORD(-1L)-dwBegin+dwEnd;
							CN_ASSERT(::GetOverlappedResult(hComm_, &RO_, &uReadReturn, FALSE));
							dwWaitTime = dwWaitTime > dwCost ? dwWaitTime-dwCost : 0;
						} 
						else
						{
							CN_ASSERT(::PurgeComm(hComm_, PURGE_RXABORT));
							break;
						}
					}
				}
				while ((dwReadResult < dwLength) && (dwWaitTime != 0));
			}
			return dwInCount_ += dwReadResult, dwReadResult;
		}
	#endif
		//! ����I/O��WinCE��I/O�� dwWaitTime������ ��ʱʱ���ɳ�ʱ�ṹ���� Ĭ���趨1/4��
		CN_ASSERT(::ReadFile(hComm_, pBuffer, dwLength, &dwReadResult, NULL));
		return dwInCount_ += dwReadResult, dwReadResult;
	}
	//! ��ȡ���� dwLength���ַ��� pBuffer ����ʵ�ʶ������ַ���  �ɶ���������
	DWORD Read(LPVOID pBuffer, DWORD dwLength, DWORD dwWaitTime = INFINITE)
	{
		CN_ASSERT(pBuffer);

		if (dwOption_ & EN_RX_BUFFER)
		{
			BlockBuffer::InnerLock locker(&I_);
			return I_.Read(pBuffer, dwLength);
		}

	#ifdef CN_COMM_FOR_CE
		return ReadPort(pBuffer, dwLength, dwWaitTime);
	#else
		return ReadPort(pBuffer, dwLength, dwWaitTime);
	#endif
	}
	//! ��ȡ���� dwLength - 1 ��ANSI�ַ��� szBuffer ���� C ģʽ�ַ���ָ�� �ʺ�һ���ַ�ͨѶ
	char * ReadString(char *szBuffer, DWORD dwLength, DWORD dwWaitTime = INFINITE)
	{
		CN_ASSERT(szBuffer && dwLength > 1);
		if (dwLength <= 1) { szBuffer[0] = '\0'; return szBuffer; }
		szBuffer[Read(szBuffer, dwLength - 1, dwWaitTime)] = '\0';
		return szBuffer;
	}
	//! ��ȡ���� dwLength - 1 ��UNICODE�ַ��� szBuffer ���� C ģʽ�ַ���ָ�� �ʺ�һ���ַ�ͨѶ
	wchar_t * ReadString(wchar_t *szBuffer, DWORD dwLength, DWORD dwWaitTime = INFINITE)
	{
		CN_ASSERT(szBuffer && dwLength > 1);
		if (dwLength <= 1) { szBuffer[0] = L'\0'; return szBuffer; }
		szBuffer[(Read(szBuffer, (dwLength - 1)*sizeof(wchar_t), dwWaitTime) +1)/ sizeof(wchar_t)] = L'\0';
		return szBuffer;
	}
	//! ֱ��д��˿�
	DWORD WritePort(LPCVOID pBuffer, DWORD dwLength)
	{
		if(!CN_ASSERT(IsOpen()) || !dwLength)
			return 0;

		DWORD dwError;
		unsigned long uWriteLength = 0;

		if(::ClearCommError(hComm_, &dwError, NULL) && dwError > 0) 
			::PurgeComm(hComm_, PURGE_TXABORT); 

	#ifndef CN_COMM_FOR_CE
		if (IsOverlappedMode())//! ʹ���ص�IO�Ƿ���0��д������ֱ�Ӽ��ϴ�д�볤�ȣ�������д��ɹ�
		{//! �ص�IO�³�ʱ�ɳ�ʱ�ṹ���� Ĭ��Ϊ����*1����+10��
			if(!::WriteFile(hComm_, pBuffer, dwLength, &uWriteLength, &WO_) 
				&& !CN_ASSERT(::GetLastError() == ERROR_IO_PENDING))
				uWriteLength = 0;
			else
				dwOutCount_ += dwLength;
		}
		else
	#endif //! ʹ������IO��WINCE���Ƿ���ʵ��д�볤�ȣ�д������ֱ�Ӽ���ʵ��д�볤��, ��ʱĬ��1/4��
			::WriteFile(hComm_, pBuffer, dwLength, &uWriteLength, NULL), dwOutCount_ += uWriteLength;

		return uWriteLength;
	}
	//! д EN_TX_BUFFER ����д�뻺��������ֱ��д��˿�
	DWORD Write(LPCVOID pBuffer, DWORD dwLength)
	{
		if (dwLength && (dwOption_&EN_TX_BUFFER))
		{
			BlockBuffer::InnerLock locker(&O_);

			O_.Write(pBuffer, dwLength);

			if (dwOption_ & EN_TX_THREAD)
				SetEvent(hWatchEvent_);
			else
			{
			#ifdef CN_COMM_FOR_CE
				SetCommMask(hComm_, dwWaitEvent_);
			#else
				if (IsOverlappedMode())
					SetCommMask(hComm_, dwWaitEvent_);
				else
					SetEvent(hWatchEvent_);
			#endif
			}
			return 0;
		}
			
	#ifdef CN_COMM_FOR_CE
		return WritePort(pBuffer, dwLength);
	#else
		return WritePort(pBuffer, dwLength);
	#endif
	}
	//! д���� ANSI�ַ� дANSI C ģʽ�ַ���ָ�� 
	DWORD Write(const char *szBuffer)
	{
		CN_ASSERT(szBuffer);
		
		return Write((LPCVOID)szBuffer, strlen(szBuffer));
	}
	//! д���� UNICODE�ַ� дANSI C ģʽ�ַ���ָ�� 
	DWORD Write(const wchar_t *szBuffer)
	{
		CN_ASSERT(szBuffer);
		
		return Write((LPCVOID)szBuffer, wcslen(szBuffer)*sizeof(wchar_t));
	}
	//! д���� szBuffer ���������ʽ�ַ��� ��������������
	DWORD Write(char *szBuffer, DWORD dwLength, char * szFormat, ...)
	{
		va_list va;
		va_start(va, szFormat);
		_vsnprintf(szBuffer, dwLength, szFormat, va);
		va_end(va);
		
		return Write(szBuffer);
	}
	//! д���� UNICODE szBuffer ���������ʽ�ַ��� ��������������
	DWORD Write(wchar_t *szBuffer, DWORD dwLength, wchar_t * szFormat, ...)
	{
		va_list va;
		va_start(va, szFormat);
		_vsnwprintf(szBuffer, dwLength, szFormat, va);
		va_end(va);
		
		return Write(szBuffer);
	}
	//! д���� szBuffer ���������ʽ�ַ��� ����黺�������� С����� \warning ��ʹ�ô˺�����ʹ��ÿ�汾 Write(char*, DWORD, char*, ...)
	DWORD Write(char *szBuffer, char * szFormat, ...)
	{
		va_list va;
		va_start(va, szFormat);
		_vsnprintf(szBuffer, 1024, szFormat, va);  //!< ʹ��1024ΪĬ�ϻ�������С
		va_end(va);
		
		return Write(szBuffer);
	}
	//! д���� szBuffer ���������ʽ�ַ��� ����黺�������� С����� \warning ��ʹ�ô˺�����ʹ��ÿ�汾 Write(wchar_t*, DWORD, wchar_t*, ...)
	DWORD Write(wchar_t *szBuffer, wchar_t * szFormat, ...)
	{
		va_list va;
		va_start(va, szFormat);
		_vsnwprintf(szBuffer, 1024, szFormat, va);  //!< ʹ��1024ΪĬ�ϻ�������С
		va_end(va);
		
		return Write(szBuffer);
	}
	//! ǿ��������������ݲ��ȴ�
	void FlushPort()
	{
		if(CN_ASSERT(IsOpen()))
			FlushFileBuffers(hComm_);
	}
	//! ǿ�����д��������ǿ��������������ݲ��ȴ�
	void Flush()
	{
		if(CN_ASSERT(IsOpen()))
		{
			if (dwOption_ & EN_TX_BUFFER)
			{
				while(O_.SafeSize())
					Sleep(50);
			}

			FlushFileBuffers(hComm_);
		}
	}
	//! ��������ַ� 
	bool TransmitChar(char c)
	{
		if (CN_ASSERT(IsOpen()))
		{
			if (::TransmitCommChar(hComm_, c))
				return dwOutCount_++, true;
		}

		return false;
	}
	//! ���������߳̿��� 
	bool BeginThread(DWORD dwThreadOption = 0) 
	{
		DWORD dwCreationFlags;

		if(CN_ASSERT(!hWatchThread_ && !hReadThread_ && !hWriteThread_)) 
		{//! ������û���߳�������״̬�²ſ��������߳�
			bContinue_		= true;
			dwCreationFlags	= dwOption_ & EN_SUSPEND ? CREATE_SUSPENDED : 0;

			if (dwThreadOption)//! �������ô��������̣߳���������д�߳�
				dwOption_ |= dwThreadOption;
			
		#if defined(_MT) && !defined(CN_COMM_FOR_CE)
			unsigned int id, rid, wid;

			if (dwOption_ & EN_THREAD)
				hWatchThread_ = (HANDLE)_beginthreadex(NULL, 0, WatchThreadProc, this, dwCreationFlags, &id);

			if (dwOption_ & EN_RX_THREAD)
				hReadThread_ = (HANDLE)_beginthreadex(NULL, 0, ReadThreadProc, this, dwCreationFlags, &rid);

			if (dwOption_ & EN_TX_THREAD)
				hWriteThread_ = (HANDLE)_beginthreadex(NULL, 0, WriteThreadProc, this, dwCreationFlags, &wid);
		#else
			DWORD id, rid, wid;

			if (dwOption_ & EN_THREAD)
				hWatchThread_ = ::CreateThread(NULL, 0, WatchThreadProc, this, dwCreationFlags , &id); 

			if (dwOption_ & EN_RX_THREAD)
				hReadThread_ = ::CreateThread(NULL, 0, ReadThreadProc, this, dwCreationFlags, &rid); 

			if (dwOption_ & EN_TX_THREAD)
				hWriteThread_ = ::CreateThread(NULL, 0, WriteThreadProc, this, dwCreationFlags, &wid); 
		#endif

			if (dwOption_ & EN_THREAD)
			{
				CN_ASSERT(hWatchThread_ != NULL);
				hWatchThreadId_ = id;

				if (!hWatchThread_)
				{
					EndThread();
					return false;
				}
				else
				{
					if (dwOption_ & EN_ABOVE_NORMAL)
						SetThreadPriority(hWatchThread_, THREAD_PRIORITY_ABOVE_NORMAL);
				}
			}

			if (dwOption_ & EN_RX_THREAD)
			{
				CN_ASSERT(hReadThread_ != NULL);
				hReadThreadId_	= rid;

				if (!hReadThread_)
				{
					EndThread();
					return false;
				}
				else
				{
					if (dwOption_ & EN_ABOVE_NORMAL)
						SetThreadPriority(hReadThread_, THREAD_PRIORITY_ABOVE_NORMAL);
				}
			}

			if (dwOption_ & EN_TX_THREAD)
			{
				CN_ASSERT(hWriteThread_ != NULL);
				hWriteThreadId_	= wid;

				if (!hWriteThread_)
				{
					EndThread();
					return false;
				}
				else
				{
					if (dwOption_ & EN_ABOVE_NORMAL)
						SetThreadPriority(hWriteThread_, THREAD_PRIORITY_ABOVE_NORMAL);
				}
			}

			return true; 
		}

		return false;
	}
	//! ��ͣ�߳�
	bool SuspendThread(int iOption = EN_THREAD)
	{
		return ::SuspendThread(GetThread(iOption)) != 0xFFFFFFFF;
	}
	//! �ָ��߳�
	bool ResumeThread(int iOption = EN_THREAD)
	{
		return ::ResumeThread(GetThread(iOption)) != 0xFFFFFFFF;
	}
	//! ��ֹ�߳�
	bool EndThread(DWORD dwWaitTime = 500)
	{
		if(hWatchThread_ || hReadThread_ || hWriteThread_) 
		{
			if ((dwOption_&EN_FLUSH_ALL) && (dwOption_&EN_TX_BUFFER))
			{//! �������EN_FLUSH_ALL����ѭ���ȴ�д��������գ����д���̲߳�������������������
				while(O_.Size())
					Sleep(50);
			}

			bContinue_ = false;

		#ifdef CN_COMM_FOR_CE
			::SetCommMask(hComm_, 0);
		#else
			if (IsOverlappedMode())
				::SetCommMask(hComm_, 0);
		#endif

			if (hWatchThread_)
			{
				SetEvent(hWatchEvent_);
				if(::WaitForSingleObject(hWatchThread_, dwWaitTime) != WAIT_OBJECT_0)
					if(!::TerminateThread(hWatchThread_, 0))
						return false;

				::CloseHandle(hWatchThread_);
				hWatchThread_ = NULL;
			}

			if (hReadThread_)
			{
				SetEvent(hReadEvent_);
				if(::WaitForSingleObject(hReadThread_, dwWaitTime) != WAIT_OBJECT_0)
					if(!::TerminateThread(hReadThread_, 0))
						return false;

				::CloseHandle(hReadThread_);
				hReadThread_ = NULL;
			}
			
			if (hWriteThread_)
			{
				SetEvent(hWriteEvent_);
				if(::WaitForSingleObject(hWriteThread_, dwWaitTime) != WAIT_OBJECT_0)
					if(!::TerminateThread(hWriteThread_, 0))
						return false;

				::CloseHandle(hWriteThread_);
				hWriteThread_ = NULL;
			}
				
			return true;
		}

		return false;
	}
	//! �رմ��� ͬʱҲ�رչ����߳�
	virtual void Close(DWORD dwWaitTime = 500)
	{
		if(IsOpen())  
		{
			EndThread(dwWaitTime);//! ͬ�������߳�

			if (dwOption_&EN_FLUSH || dwOption_&EN_FLUSH_ALL)
				FlushFileBuffers(hComm_);

			::PurgeComm(hComm_, PURGE_TXABORT | PURGE_TXCLEAR | PURGE_RXCLEAR | PURGE_RXABORT); 
			::CloseHandle(hComm_);
			hComm_ = INVALID_HANDLE_VALUE;
		}
	}
	//! ����
	void Lock()							
	{	
		::EnterCriticalSection(&CS_);		
	}
	//! ����
	void Unlock()						
	{	
		::LeaveCriticalSection(&CS_);		
	}
	//! �Զ��� ���ں����ڲ� ���ö�������������������������
	struct InnerLock
	{
		CnComm* ptr;//!< CnComm ����ָ��
		//! ����
		InnerLock(CnComm* p) : ptr(p)	
		{	
			ptr->Lock();						
		}
		//! ����
		~InnerLock()					
		{	
			ptr->Unlock();						
		}
	};
	//! ��ô��ڲ��� DCB
	DCB *GetState(DCB *pDcb = NULL)
	{
		return CN_ASSERT(IsOpen()) && ::GetCommState(hComm_, pDcb == NULL ? &DCB_ : pDcb) == TRUE ? (pDcb == NULL ? &DCB_ : pDcb) : NULL;
	}
	//! ���ô��ڲ��� DCB
	bool SetState(DCB *pDcb = NULL)
	{
		return CN_ASSERT(IsOpen()) ? ::SetCommState(hComm_, pDcb == NULL ? &DCB_ : pDcb) == TRUE : false;
	}
	//! ���ô��ڲ����������ʣ�ֹͣλ���� ***
	bool SetState(DWORD dwBaudRate, BYTE btParity = NOPARITY, BYTE btByteSize = 8, BYTE btStopBits = ONESTOPBIT)
	{
		if(CN_ASSERT(IsOpen()))
		{
			if(::GetCommState(hComm_, &DCB_) != TRUE)
				return false;

			DCB_.BaudRate = dwBaudRate;
			DCB_.ByteSize = btByteSize;
			DCB_.Parity   = btParity;
			DCB_.StopBits = btStopBits;
			DCB_.fParity  = (btParity != NOPARITY);

			return ::SetCommState(hComm_, &DCB_) == TRUE;
		}
		return false;
	}
#ifndef CN_COMM_FOR_CE
	//! ���ô��ڲ��� ֧�������ַ��� "9600, n, 8, 1"
	bool SetState(LPCTSTR szSetStr) 
	{
		if(CN_ASSERT(IsOpen()))
		{
			if(!::GetCommState(hComm_, &DCB_))
				return false;

			if(!BuildCommDCB(szSetStr, &DCB_))
				return false;

			DCB_.fParity  = (DCB_.Parity != NOPARITY);
			return ::SetCommState(hComm_, &DCB_) == TRUE;
		}

		return false;
	}
#endif
	//! ��ó�ʱ�ṹ
	LPCOMMTIMEOUTS GetTimeouts(LPCOMMTIMEOUTS lpCO = NULL)
	{
		return CN_ASSERT(IsOpen()) && ::GetCommTimeouts(hComm_, lpCO ? lpCO : &CO_) == TRUE  ? (lpCO ? lpCO : &CO_) : NULL;
	}
	//! ���ó�ʱ
	bool SetTimeouts(LPCOMMTIMEOUTS lpCO = NULL)
	{
		return CN_ASSERT(IsOpen()) ? ::SetCommTimeouts(hComm_, lpCO ? lpCO : &CO_) == TRUE : false;
	}
	//! ���ô��ڵ�I/O��������С
	bool Setup(DWORD dwInputSize = 4096, DWORD dwOutputSize = 4096)
	{
		return CN_ASSERT(IsOpen()) ? ::SetupComm(hComm_, dwInputSize, dwOutputSize) == TRUE : false; 
	}
	//! �����˿ڹ���
	bool Escape(DWORD dwType)
	{
		return CN_ASSERT(IsOpen()) ? EscapeCommFunction(hComm_, dwType) != 0 : false;
	}
	//! ��õ��ƽ��������ź�״̬
	DWORD GetModemStatus()
	{
		DWORD dwModemStat = 0;
		return CN_ASSERT(IsOpen()) && GetCommModemStatus(hComm_, &dwModemStat) ? dwModemStat : 0;
	}
	//! ��ö˿ڲ��� \param[in] pCP �ṹָ�� ���pCP==NULL, CnComm���Ӷѷ����ڴ�, ����CnComm�����ͷ�, �û�����Ҫ�Լ��ͷ��ڴ�
	LPCOMMPROP GetProperties(LPCOMMPROP pCP = NULL)	
	{
		if (CN_ASSERT(IsOpen()))
		{
			if (!pCP)
			{
			#ifdef CN_COMM_FOR_CE
				USHORT dwSize = sizeof(COMMPROP);
			#else
				USHORT dwSize = sizeof(COMMPROP) + sizeof(MODEMDEVCAPS);
			#endif

				if (!pCP_)
					pCP_ = (LPCOMMPROP) new BYTE[dwSize];

				if (pCP_)
				{
					memset(pCP_, 0, dwSize);

					pCP_->wPacketLength = dwSize;
				#ifndef CN_COMM_FOR_CE
					pCP_->dwProvSubType = PST_MODEM;
				#endif
					pCP_->dwProvSpec1	= COMMPROP_INITIALIZED;
					pCP = pCP_;
				}
			}
		}

		return pCP && GetCommProperties(hComm_, pCP) ? pCP : NULL;
	}
	//! ��ȡ�¼���ʶ
	DWORD GetMask()
	{
		DWORD dwMask;
		return CN_ASSERT(IsOpen()) && GetCommMask(hComm_, &dwMask) ? dwMask : 0;	
	}
	//! ����˿ڻ�����
	bool Purge(DWORD dwPara = PURGE_TXABORT | PURGE_TXCLEAR | PURGE_RXABORT | PURGE_RXCLEAR)
	{
		return CN_ASSERT(IsOpen()) ? ::PurgeComm(hComm_, dwPara)==TRUE : false;
	}
	//! ��ô������
	DWORD ClearError()
	{
		DWORD dwError;
		return CN_ASSERT(IsOpen()) && ::ClearCommError(hComm_, &dwError, NULL) ? dwError : 0;
	}
	//! ��ö��������������ַ���
	DWORD GetQueueCount(bool bInput = true)
	{
		COMSTAT Stat;
		DWORD dwError;
		
		return CN_ASSERT(IsOpen()) && ::ClearCommError(hComm_, &dwError, &Stat) ? (bInput ? Stat.cbInQue : Stat.cbOutQue) : (DWORD)-1L;
	}
	//! ���ƽ���� CTS ON
	bool CheckCTS()				
	{	
		return (GetModemStatus()&MS_CTS_ON) != 0;		
	}
	//! ���ƽ���� DSR ON
	bool CheckDSR()				
	{	
		return (GetModemStatus()&MS_DSR_ON) != 0;		
	}
	//! ���ƽ���� Ring ON
	bool CheckRING()				
	{	
		return (GetModemStatus()&MS_RING_ON) != 0;		
	}
	//! ���ƽ���� RLSD ON
	bool CheckRLSD()				
	{	
		return (GetModemStatus()&MS_RLSD_ON) != 0;		
	}
	//! DTR ��ƽ����
	bool SetDTR(bool bSetOrClr = true)	
	{	
		return Escape(bSetOrClr ? SETDTR : CLRDTR);		
	}
	//! RTS ��ƽ����
	bool SetRTS(bool bSetOrClr = true)	
	{	
		return Escape(bSetOrClr ? SETRTS : CLRRTS);		
	}
	//! ���ƽ����
	bool SetBreak(bool bSetOrClr = true)	
	{	
		return Escape(bSetOrClr ? SETBREAK : CLRBREAK);	
	}
#ifdef CN_COMM_FOR_CE
	//! WINCE
	bool SetIR(bool bSetOrClr)	
	{	
		return Escape(bSetOrClr ? SETIR : CLRIR);	
	}
#endif
	//! ������ SETXON SETXOFF
	bool SetX(bool bOnOrOff)				
	{	
		return Escape(bOnOrOff ? SETXON : SETXOFF);							
	}
	//! ����ͨѶ�ص㿪���Ļ������� ���������ڴ�� ��һЩ��չ��֧�ֺ�API�ҽ� 
	class BlockBuffer
	{
	public:
		//! �������ڴ��
		struct Block
		{
			DWORD			B_;		//!< ��ʼƫ��
			DWORD			E_;		//!< ����ƫ��
			DWORD			S_;		//!< ���С �ڴ�����ֵ���� �ڴ����Сֵ��CN_COMM_BUFFER_MIN_BLOCK_SIZE���� 
			Block*			N_;		//!< ��һ����ָ�� 
			BYTE			P_[4];	//!< ������ָ�� ʵ�ʴ�С��S_���� 
		
			//! ����
			DWORD Capacity()		{	return S_;			}
			//! ʵ�ʴ�С
			DWORD Size()			{	return E_ - B_;		}
			//! ��ʼ������ָ��
			BYTE* Begin()			{	return P_ + B_;		}
			//! ĩ�˻�����ָ��
			BYTE* End()				{	return P_ + E_;		}
			//! ��һ����
			Block* Next()			{	return N_;			}
			//! �Ƿ��
			bool IsEmpty()			{	return B_ == E_;	}
			//! ���д�С
			DWORD FreeSize()		{	return S_ - E_;		}
		};

		//! ���ڻ��������������
		struct Iterator
		{
			BlockBuffer*	P_;		//!< ����ָ��
			Block*			B_;		//!< ��ǰ��ָ��
			DWORD			I_;		//!< ��ǰ��ƫ��
			DWORD			O_;		//!< ȫ������ƫ��

			//! ����
			Iterator(BlockBuffer *P = NULL, Block* B = NULL, DWORD I = 0, DWORD O = 0) 
				: P_(P), B_(B), I_(I), O_(O)	
			{										
			}
			//! �Ƿ���Ч
			operator bool()				
			{	
				return B_ && I_<B_->E_&&I_>=B_->B_;	
			}
			//! �Ƿ��д
			bool CanWrite()				
			{	
				return B_ && I_ < B_->S_;			
			}
			//! ȡֵ����
			BYTE& operator *()			
			{	
				CN_ASSERT( P_ && B_ && I_<B_->E_&&I_>=B_->B_);
				return B_->P_[I_];					
			}
			//! �ƶ������� ++Iter;
			Iterator& operator ++ ()		
			{
				return operator +=(1);			
			}
			//! �ƶ������� Iter++;
			Iterator& operator ++ (int)	
			{
				return operator +=(1);				
			}
			//! �ƶ�������  \param dwOffset Ϊƫ����
			Iterator& operator += (DWORD dwOffset)
			{
				while (dwOffset) 
				{
					if (I_+dwOffset < B_->E_)
						I_ += dwOffset, O_ += dwOffset, dwOffset = 0; 
					else
						dwOffset -= B_->E_-I_, I_ += B_->E_-I_, O_ += B_->E_-I_, B_ = B_->N_, I_ = 0;
				}

				return *this;
			}
			//! �Ƚ�
			bool operator == (const Iterator& iter)
			{
				return (P_ == iter.P_) && (B_ == iter.B_) && (I_ == iter.I_);
			}
		};
		//! ��Ԫ
		friend struct Iterator;
		//! ����
		void Lock()							
		{	
			::EnterCriticalSection(&C_);			
		}
		//! ����
		void Unlock()						
		{	
			::LeaveCriticalSection(&C_);			
		}
		//! �Զ���
		struct InnerLock
		{
			BlockBuffer* ptr;//!<����ָ��
			///����
			InnerLock(BlockBuffer* p) : ptr(p)	
			{
				if (ptr)
					ptr->Lock();						
			}
			///����
			~InnerLock()					
			{
				if (ptr)
					ptr->Unlock();						
			}
		};
		//! ����
		BlockBuffer()
		{
			::InitializeCriticalSection(&C_);
			S_ = 0, F_ = L_ = NULL, M_ = CN_COMM_BUFFER_MIN_BLOCK_SIZE;
		}
		//! �����Զ��ͷſռ�
		virtual ~BlockBuffer()
		{
			Clear(true);
			::DeleteCriticalSection(&C_);
		}
		//! �����ʼ������
		Iterator Begin()					
		{	
			return Iterator(this, F_, F_? F_->B_ : 0, 0);	
		}
		//! ���ÿ����С����
		void SetMinBlockSize(DWORD dwMinSize)
		{
			M_ = dwMinSize;
		}
		//! ��ÿ����С����
		DWORD GetMinBlockSize()
		{
			return M_;
		}
		//! �������������ֽ���
		DWORD Size()						
		{	
			return S_;								
		}
		//! ��������С
		DWORD SafeSize()						
		{
			InnerLock lock(this);
			return S_;								
		}
		//! д��ANSI�ַ��������� \sa Write(LPCVOID lpBuf, DWORD dwSize)
		DWORD Write(const char* lpBuf)
		{
			return Write(lpBuf, strlen(lpBuf));
		}
		//! д��UNICODE�ַ��������� \sa Write(LPCVOID lpBuf, DWORD dwSize)
		DWORD Write(const wchar_t* lpBuf)
		{
			return Write(lpBuf, wcslen(lpBuf)*sizeof(wchar_t));
		}
		//! д�뻺���� \param[out] lpBuf Ŀ�껺���� \param[in] dwSize �����ֽ��� \return ʵ�ʸ��������ֽ���
		DWORD Write(LPCVOID lpBuf, DWORD dwSize)
		{
			DWORD dwTemp = dwSize, dwFree = FreeSize(), dwCopy = 0;
			
			if (dwFree)//! ���Ȳ���ĩβ���У���д������
			{
				dwCopy = dwFree > dwSize ? dwSize : dwFree;
				memcpy(L_->P_ + L_->E_, lpBuf, dwCopy);
				dwTemp -= dwCopy, L_->E_ += dwCopy;
			}

			if (dwTemp)//! ʣ������ݷ����µĿռ䲢д��
			{
				memcpy(NewBlock(dwSize)->P_, ((LPBYTE)lpBuf )+ dwCopy, dwTemp);
				L_->E_ += dwTemp;
			}

			S_ += dwSize;
			return dwSize;
		}
		//! �̰߳�ȫд�뻺���� \sa Write(LPCVOID lpBuf, DWORD dwSize)
		DWORD SafeWrite(LPCVOID lpBuf, DWORD dwSize)
		{
			InnerLock lock(this);
			return Write(lpBuf, dwSize);
		}
		//! �̰߳�ȫд��ANSI�ַ��������� \sa Write(LPCVOID lpBuf, DWORD dwSize)
		DWORD SafeWrite(const char* lpBuf)
		{
			InnerLock lock(this);
			return Write(lpBuf, strlen(lpBuf));
		}
		//! �̰߳�ȫд��UNICODE�ַ��������� \sa Write(LPCVOID lpBuf, DWORD dwSize)
		DWORD SafeWrite(const wchar_t* lpBuf)
		{
			InnerLock lock(this);
			return Write(lpBuf, wcslen(lpBuf)*sizeof(wchar_t));
		}
		//! �������� \param[out] lpBuf Ŀ�껺���� \param[in] dwSize �����ֽ��� \param[in] dwStart Դ��������ʼƫ��ֵ \return ʵ�ʸ��������ֽ���
		DWORD Copy(LPVOID lpBuf, DWORD dwSize, DWORD dwStart = 0)
		{
			CN_ASSERT(lpBuf);

			if (!F_ || !dwSize || dwStart >= S_)
				return 0;

			DWORD dwTemp, dwIndex;
			Block * pCur = F_, *pNext = F_->N_;

			for (dwTemp = 0, dwIndex = pCur->B_; dwTemp < dwStart; pCur = pCur->N_, dwIndex = pCur ? pCur->B_ : 0)
			{
				if (dwStart - dwTemp < pCur->E_ - pCur->B_)
				{
					dwIndex = pCur->B_ + dwStart - dwTemp;
					break;
				}

				dwTemp += pCur->E_ - pCur->B_;
			}

			for (dwTemp = 0; dwTemp < dwSize && pCur; pCur = pCur->N_, dwIndex = pCur ? pCur->B_ : 0)
			{
				if (dwSize - dwTemp < pCur->E_ - dwIndex)
				{
					memcpy((LPBYTE)lpBuf+dwTemp, pCur->P_ + dwIndex, dwSize - dwTemp );
					dwTemp = dwSize;
					break;
				}
				else
				{
					memcpy((LPBYTE)lpBuf+dwTemp, pCur->P_ + dwIndex, pCur->E_ - dwIndex);
					dwTemp += pCur->E_ - dwIndex;
				}
			}

			return dwTemp;
		}
		//! �̰߳�ȫ�������� \sa Copy(LPVOID lpBuf, DWORD dwSize, DWORD dwStart=0)
		DWORD SafeCopy(LPVOID lpBuf, DWORD dwSize, DWORD dwStart = 0)
		{
			InnerLock lock(this);
			return Copy(lpBuf, dwSize, dwStart);
		}
		/*! \param[out] lpBuf Ŀ�껺���� ΪNULLʱ��ɾ������������  \param[in] dwSize ���������ֽ��� \return ʵ�ʸ��ƻ�ɾ���ֽ��� */
		//! ���Ʋ�ɾ�������������ݵ�lpBuf
		DWORD Read(LPVOID lpBuf, DWORD dwSize)
		{
			DWORD dwTemp = 0, dwCopy;

			for (Block * pCur = F_, *pNext = NULL; dwTemp<dwSize && pCur; pCur = pNext)
			{
				if (dwSize-dwTemp > pCur->E_-pCur->B_ )
					dwCopy = pCur->E_ - pCur->B_; 
				else
					dwCopy = dwSize - dwTemp;

				if (lpBuf) 
					memcpy((LPBYTE)lpBuf+dwTemp, pCur->P_ + pCur->B_, dwCopy);

				pNext = pCur->N_, dwTemp += dwCopy;

				if (dwCopy == pCur->E_-pCur->B_)
				{//! ɾ��������ȫ���п�, ��һ�㱣��1����, ��С��4*CN_COMM_BUFFER_MIN_BLOCK_SIZE������� 
					if (pNext || pCur->S_>(M_<<2))
					{
						delete[] (BYTE*)pCur;
						F_ = pNext;
						if (!F_)
							L_ = NULL;
					}
					else
						pCur->B_ = pCur->E_ = 0;
				}
				else
					pCur->B_ += dwCopy;

				S_ -= dwCopy;
			}

			return dwTemp;
		}
		//! ����ANSI�ַ���������
		char* ReadString(char* lpBuf, DWORD dMaxSize)
		{
			lpBuf[Read(lpBuf, dMaxSize)] = '\0';
			return lpBuf;
		}
		//! ����UNICODE�ַ���������
		wchar_t* ReadString(wchar_t* lpBuf, DWORD dMaxSize)
		{
			lpBuf[(Read(lpBuf, dMaxSize*sizeof(wchar_t))+1) / sizeof(wchar_t)] = L'\0';
			return lpBuf;
		}
		//! �̰߳�ȫ�Ķ�����
		DWORD SafeRead(LPVOID lpBuf, DWORD dwSize)
		{
			InnerLock lock(this);
			return  Read(lpBuf, dwSize);
		}
		//! �̰߳�ȫ����ANSI�ַ���������
		char* SafeReadString(char* lpBuf, DWORD dMaxSize)
		{
			InnerLock lock(this);
			return ReadString(lpBuf, dMaxSize);
		}
		//! �̰߳�ȫ����UNICODE�ַ���������
		wchar_t* SafeReadString(wchar_t* lpBuf, DWORD dMaxSize)
		{
			InnerLock lock(this);
			return ReadString(lpBuf, dMaxSize);
		}
		//! ��� \param bDeleteAll Ϊtrueʱ�ͷ������ڴ�, ������һ���ڴ�������Ч��
		void Clear(bool bDeleteAll = false)
		{
			if (!bDeleteAll && F_ && (F_==L_) && (F_->S_>(M_<<2)))
			{
                DWORD S = F_->S_;
                memset(F_, 0, sizeof(Block)), F_->S_ = S;
            }
			else
			{
				for (Block* t = F_;  t; delete  F_)
					F_ = t, t = t->N_;

				F_ = L_ = NULL, S_ = 0;
			}
		}
		//! �̰߳�ȫ���������  \sa void Clear(bool bDeleteAll = false)
		void SafeClear(bool bDeleteAll = false)
		{
			InnerLock lock(this);
			Clear(bDeleteAll);
		}
		//! ����ڴ��ָ�� \param bFirst Ϊtrueʱ�������ͷ��ָ�����������β��ָ��
		Block* GetBlockPtr(bool bFirst = true)	
		{	
			return bFirst ? F_ : L_;						
		}
		//! ������β���Ŀ��пռ�
		DWORD FreeSize()					
		{	
			return L_ ? L_->S_-L_->E_ : 0 ;			
		}
		//! ��ù�API�������ݵ�ֱд������ ���������СdwSize ���в�������¿� ����0����β���Ŀ���ָ�� β���޿��з���NULL 
		LPVOID GetFreePtr(DWORD dwSize = 0)
		{
			if (dwSize)
				return FreeSize() > dwSize ? L_->P_ + L_->E_ : NewBlock(dwSize)->P_;
			else
				return L_ ? L_->P_ + L_->E_ : NULL;
		}
		/*! \param[in] dwSize ������������ȫ��
			\code strcpy(GetFreePtr(100), "test"), Release(4); //��ȡ100�ֽڵĻ����� �����ĸ��ֽ� ������С����4���ֽ� \endcode
		*/
		//! ����APIֱ��д����GetFreePtr()��ÿ���ָ��, ͬ��������������С 
		DWORD Release(DWORD dwSize)
		{
			return (dwSize <= L_->S_) ? (L_->E_ += dwSize, S_ += dwSize, dwSize) : 0;		
		}
		//! ��õ�һ����Ч��Ļ�����ָ��
		LPVOID GetPtr()
		{
			return F_ ? F_->P_ + F_->B_ : NULL;
		}
		//! ��õ�һ����Ч��Ļ�����ָ��ָ������ݴ�С
		DWORD GetPtrSize()
		{
			return F_ ? F_->E_ - F_->B_ : 0;
		}
		//! ������� �����������1 Ч�ʺܵ� �Ƽ��õ����ӷ��ʿ��Ի����������
		BYTE& operator[](DWORD dwOffset)
		{
			CN_ASSERT(F_);

			if (F_ == L_)	
			{
				CN_ASSERT(F_->S_ > dwOffset);
				return F_->P_[dwOffset];
			}
			else			
			{
				Iterator iter = Begin();
				iter += dwOffset;
				CN_ASSERT(iter);
				return *iter;
			}
		}
		
	protected:

		//! �½��� �Զ�������β��
		Block* NewBlock(DWORD dwSize)
		{
			dwSize = dwSize < M_ ? M_ : dwSize;
			Block * pNew = (Block *) new BYTE[sizeof(Block) - 4 + dwSize];

			if (pNew)
			{
				memset(pNew, 0, sizeof(Block));
				pNew->S_ = dwSize;

				if (L_)
					L_->N_ = pNew, L_ = pNew;
				else
					F_ = L_ = pNew;
			}
			
			return pNew;
		}

		Block*				F_;//!< ͷָ��
		Block*				L_;//!< βָ��
		DWORD				S_;//!< ��С
		DWORD				M_;//!< ����С����
		CRITICAL_SECTION	C_;//!< ���ṹ
	};

#if defined(CN_COMM_MFC_EXCEPTION)
	/*! ��Ҫ����� CN_COMM_MFC_EXCEPTION CN_ASSERT \n ��ʹ��throw new MfcException(msg);����׳�MFC�쳣(VC++) */
	//! ����MFC���쳣  
	class MfcException : public CException
	{
	public:
		//! ���캯����Ҫ��CException�Զ�����
		MfcException(LPCTSTR szMsg) : CException(TRUE)
		{
			lstrcpy(szMsg_, szMsg);

		#ifdef _DEBUG
			CException::m_bReadyForDelete = TRUE;
		#endif
		}
		//! ������ʾ��Ϣ
		BOOL GetErrorMessage( LPTSTR lpszError, UINT nMaxError, PUINT pnHelpContext = NULL )
		{
		#ifndef CN_COMM_FOR_CE
			lstrcpyn(lpszError, szMsg_, nMaxError);
		#else
			_tcsncpy(lpszError, szMsg_, nMaxError - 1);
			lpszError[nMaxError - 1] = _T('\0');
		#endif
			return TRUE;
		}
	protected:
		TCHAR szMsg_[256]; //!< ������Ϣ ��ʽ��CN_ASSERT(����ʽ) failed; CnComm(�к�); Code(GetLastError()); �����������
	};
#endif

	//! �û������쳣 ���׳��쳣; δ�����쳣: DEBUG�汾 ����̨�汾���������Ϣ ���˳�; Release�汾������ʾ����Ӧ�û�Ҫ��
	static bool Assert(LPCTSTR szMessage)
	{
	#if defined(_DEBUG) || defined(CN_COMM_STD_EXCEPTION) || defined(CN_COMM_VCL_EXCEPTION) || defined(CN_COMM_MFC_EXCEPTION)
		TCHAR szMsg[256];
		DWORD dwError, dwLength;
		
		_tcscpy(szMsg, szMessage);

		dwError = GetLastError();
		if (dwError)//! �������(GetLastError())��Ϊ 0 �����������  
		{
			dwLength = _tcslen(szMsg);
			_sntprintf(szMsg + dwLength, 256 - _tcslen(szMsg), _T("Code:%d; "), dwError);
			dwLength = _tcslen(szMsg);

			FormatMessage(
				FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
				NULL,
				dwError,
				MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),	//! �����������ñ�������
				szMsg + dwLength - 1,							
				256 - dwLength - 1,									
				NULL
				);
		}
	#else 
		;// Release�汾 ʲô������  Ԥ��
	#endif

	#if	defined(CN_COMM_STD_EXCEPTION)

		#ifdef _UNICODE
			char szTemp[512] = {0};
			WideCharToMultiByte(CP_ACP, 0, szMsg, -1, szTemp, wcslen(szMsg)*sizeof(wchar_t), NULL, NULL);
			throw std::runtime_error(szTemp);
		#else
			throw std::runtime_error(szMsg);
		#endif

	#elif defined(CN_COMM_VCL_EXCEPTION)

		throw Exception(szMsg);

	#elif defined(CN_COMM_MFC_EXCEPTION)

		throw (new MfcException(szMsg));

	#elif defined(_DEBUG)

		OutputDebugString(szMsg);
		#ifdef _CONSOLE
			// ��Ҫ setlocale(LC_ALL, "chs"); ����̨�ſ�����ȷ���UNICODE���� ����ת��ANSI ������������
			#ifdef _UNICODE
				char szTemp[512] = {0};
				WideCharToMultiByte(CP_ACP, 0, szMsg, -1, szTemp, 512, NULL, NULL);
				fprintf(stderr, "%s", szTemp);
			#else
				fprintf(stderr, "%s", szMsg);
			#endif

			system("pause");
			exit(1);
		#else
			switch(MessageBox(NULL, szMsg, _T("CN_ASSERT"), MB_ABORTRETRYIGNORE))
			{
			case IDABORT:
				exit(1);

			case IDRETRY:
				DebugBreak();
				break;

			case IDIGNORE:
				break;
			}
		#endif

	#else 
		;// Release�汾 ʲô������  Ԥ��
	#endif
		return false;
	}

protected:

	DWORD				dwOption_;			//!< �ؼ�ģʽ���� �ڹ��캯�����趨
	HANDLE				hComm_;				//!< ���ھ��
	DWORD				dwPort_;			//!< ���ں� 0Ϊ���⴮�� -1Ϊ��Ч ��Ҫ������Ϣ֪ͨ���
	TCHAR				szName_[64];		//!< ���洮������ ����COM1���ַ���
	CRITICAL_SECTION	CS_;				//!< �ٽ绥����
	DCB					DCB_;				//!< �����ʣ�ֹͣλ����   
	COMMTIMEOUTS		CO_;				//!< ��ʱ�ṹ 
	COMMPROP*			pCP_;				//!< ���ڲ���

	BlockBuffer			I_;					//!< ��������
	BlockBuffer			O_;					//!< д������
	DWORD				dwInCount_;			//!< ������
	DWORD				dwOutCount_;		//!< д����

	bool				bContinue_;			//!< �̼߳�������ѭ����־
	DWORD				dwWaitEvent_;		//!< WaitCommEvent �ļ����¼�

	HANDLE				hWatchThread_;		//!< ���Ӹ����߳�
	DWORD				hWatchThreadId_;	//!< ���Ӹ����߳� ID
	HANDLE				hWatchEvent_;		//!< ֪ͨ�����߳�

	HANDLE				hReadThread_;		//!< ���ո����߳� ʵ��˫�����Ч��
	DWORD				hReadThreadId_;		//!< ���ո����߳� ID
	HANDLE				hReadEvent_;		//!< ֪ͨ�����߳�

	HANDLE				hWriteThread_;		//!< ���͸����߳� ʵ��˫�����Ч��
	DWORD				hWriteThreadId_;	//!< ���͸����߳� ID
	HANDLE				hWriteEvent_;		//!< ֪ͨ�����߳�

	HWND				hNotifyWnd_;		//!< ֪ͨ����
	DWORD				hNotifyThreadId_;	//!< ֪ͨ�߳�
	DWORD				dwNotifyNum_;		//!< ���ܶ����ֽ�(>=dwNotifyNum_)����֪ͨ��Ϣ

#ifndef CN_COMM_FOR_CE
	OVERLAPPED			RO_;				//!< �ص�I/O ReadFile
	OVERLAPPED			WO_;				//!< �ص�I/O WriteFile
	OVERLAPPED			EO_;				//!< �ص�I/O WaitCommEvent 
#endif

	//! ��ʼ��
	virtual void Init() 
	{
		::InitializeCriticalSection(&CS_);

		memset(szName_, 0, 64*sizeof(TCHAR));

		memset(&DCB_,	0, sizeof(DCB_));
		DCB_.DCBlength	= sizeof(DCB_);

		hComm_				= INVALID_HANDLE_VALUE;
		dwPort_				= (DWORD)-1;
		dwOutCount_			= 0;
		dwInCount_			= 0;
		
		dwWaitEvent_		= CN_COMM_WAIT_EVENT;
		hWatchThread_		= NULL;
		hReadThread_		= NULL;
		hWriteThread_		= NULL;
		hWatchThreadId_		= 0;
		hReadThreadId_		= 0;
		hWriteThreadId_		= 0;
		
		hNotifyWnd_			= NULL;
		dwNotifyNum_		= 0;
		hNotifyThreadId_	= 0;
		pCP_				= NULL;

	#ifndef CN_COMM_FOR_CE
		memset(&RO_, 0, sizeof(RO_));
		memset(&WO_, 0, sizeof(WO_));
		memset(&EO_, 0, sizeof(EO_));
		
		RO_.hEvent = ::CreateEvent(NULL, TRUE, FALSE, NULL);
		CN_ASSERT(RO_.hEvent != NULL); 
		
		WO_.hEvent = ::CreateEvent(NULL, TRUE, FALSE, NULL);
		CN_ASSERT(WO_.hEvent != NULL);
		
		EO_.hEvent= ::CreateEvent(NULL, TRUE, FALSE, NULL);
		CN_ASSERT(EO_.hEvent != NULL); 
	#endif

		hWatchEvent_	= ::CreateEvent(NULL, TRUE, FALSE, NULL);
		CN_ASSERT(hWatchEvent_ != NULL); 
		hReadEvent_		= ::CreateEvent(NULL, TRUE, FALSE, NULL);
		CN_ASSERT(hReadEvent_ != NULL); 
		hWriteEvent_	= ::CreateEvent(NULL, TRUE, FALSE, NULL);
		CN_ASSERT(hWriteEvent_ != NULL); 
	} 
	//! ����
	virtual void Destroy()
	{
	#ifndef CN_COMM_FOR_CE
		if(RO_.hEvent != NULL)
			CloseHandle(RO_.hEvent);
		
		if(WO_.hEvent != NULL)
			CloseHandle(WO_.hEvent);
		
		if(EO_.hEvent != NULL)
			CloseHandle(EO_.hEvent);
	#endif

		if(hWatchEvent_ != NULL)
			CloseHandle(hWatchEvent_);

		if(hReadEvent_ != NULL)
			CloseHandle(hReadEvent_);

		if(hWriteEvent_ != NULL)
			CloseHandle(hWriteEvent_);

		if (pCP_)
			delete[] ((BYTE*)pCP_);

		::DeleteCriticalSection(&CS_);
	}
	//! �󶨴��� 
	void BindPort(DWORD dwPort)
	{
		dwPort_ = dwPort;

	#if defined(CN_COMM_FOR_CE)
		wsprintf(szName_, _T("COM%d:"), dwPort);
	#else
		wsprintf(szName_, _T("\\\\.\\COM%d"), dwPort);
	#endif
	}
	//! �򿪴��� 
	virtual bool OpenPort()
	{
		CN_ASSERT(!IsOpen());

		if(IsOpen())
			Close();
		
		hComm_ = ::CreateFile(
			szName_,
			GENERIC_READ | GENERIC_WRITE,
			0,
			NULL,
			OPEN_EXISTING,
			FILE_ATTRIBUTE_NORMAL | (IsOverlappedMode() ? FILE_FLAG_OVERLAPPED : 0),
			NULL
			);
		
		return IsOpen();
	}
	//! ���ô��� 
	virtual bool SetupPort()
	{
		if(!CN_ASSERT(IsOpen()))
			return false;

		#if defined(CN_COMM_FOR_CE)
			::SetupComm(hComm_, 4096, 4096);
		#else
			if(!CN_ASSERT(::SetupComm(hComm_, 4096, 4096)))//! ���ö˿ڷ��ͽ��ն��д�С, ��4096�ֽ�, д4096�ֽ�, ����I/Oģʽ���Ͷ���������
			return false; 
		#endif
		
		if(!CN_ASSERT(::GetCommTimeouts(hComm_, &CO_)))
			return false;

		CO_.ReadIntervalTimeout			= 100;//! ���ó�ʱ�ṹ �ַ���С���100ms
		CO_.ReadTotalTimeoutMultiplier	= 0;
		CO_.ReadTotalTimeoutConstant	= IsOverlappedMode() ? 500 : 250;//! ����ʱ �ص�I/Oģʽ��500���� ����I/Oģʽ��250����
		CO_.WriteTotalTimeoutMultiplier = IsOverlappedMode() ? 1 : 0;
		CO_.WriteTotalTimeoutConstant	= IsOverlappedMode() ? 10000 : 250;//! д��ʱ �ص�I/Oģʽ��(10000+1���ֽ���)���� ����I/Oģʽ��250����

		if(!CN_ASSERT(::SetCommTimeouts(hComm_, &CO_)))
			return false; 
		
		if(!CN_ASSERT(::PurgeComm(hComm_, PURGE_TXABORT | PURGE_RXABORT | PURGE_TXCLEAR | PURGE_RXCLEAR )))//! ����˿�
			return false; 
		
		return true;
	} 
	//! ���˿����ݶ��뻺������
	DWORD PortToBuffer(DWORD dwPortByteNum)
	{
		BlockBuffer::InnerLock locker(&I_);
		return dwPortByteNum ? I_.Release(ReadPort(I_.GetFreePtr(dwPortByteNum), dwPortByteNum)) : 0;
	}
	//! ��������������д��˿� 
	DWORD BufferToPort(DWORD dwMaxSize = 1024)
	{
		if (IsOverlappedMode())
		{
			BlockBuffer::InnerLock locker(&O_);

			if (!O_.Size())
				return 0;

			DWORD dwWrite = dwMaxSize > O_.GetPtrSize() ? O_.GetPtrSize() : dwMaxSize;
			WritePort(O_.GetPtr(), dwWrite);
			return O_.Read(NULL, dwWrite);
		}
		else
		{
			BYTE btTemp[1024];
			DWORD dwLength, dwIndex = 0;

			O_.Lock();
			dwLength = O_.Read(btTemp, 1024);
			O_.Unlock();

			while ( dwIndex < dwLength )
				dwIndex += WritePort(btTemp + dwIndex, dwLength - dwIndex);

			return dwLength;
		}
	}
	/*! \param uMsg ��Ϣ \param lParam ���� \param bPostMode ����PostMessage����SendMessage������Ϣ*/
	//! �����ھ�����߳�ID��Ч, �ͳ���Ϣ, ������Ӧ�¼�֪ͨ, WPARAMĬ�ϰ������ڱ�� 
	virtual void Notify(UINT uMsg, LPARAM lParam = 0, bool bPostMode = true)
	{
		if(hNotifyWnd_ && ::IsWindow(hNotifyWnd_))//���ھ����Ч
		{
			if (bPostMode)
				PostMessage(hNotifyWnd_, uMsg, WPARAM(dwPort_), lParam);
			else
				SendMessage(hNotifyWnd_, uMsg, WPARAM(dwPort_), lParam);
		}

		if (hNotifyThreadId_)//�߳�ID��Ч
			PostThreadMessage(hNotifyThreadId_, uMsg, WPARAM(dwPort_), lParam);
	}
	//---------------------------------------threads callback-----------------------------------------------------
	//! ��ӦEV_RXCHAR�¼� ���̻߳ص�, �麯�������ڻ���������չ(�Ƽ���ʽ)    
	virtual void OnReceive() 
	{
		Notify(ON_COM_RECEIVE);
	}
	//! ��ӦEV_DSR�¼�
	virtual void OnDSR()
	{
		Notify(ON_COM_DSR, CheckDSR() ? 1 : 0);
	}
	//! ��ӦEV_CTS�¼�
	virtual void OnCTS()
	{
		Notify(ON_COM_CTS, CheckCTS() ? 1 : 0);
	}
	//! ��ӦEV_BREAK�¼�
	virtual void OnBreak()
	{
		ClearCommBreak(hComm_);
		Notify(ON_COM_BREAK);
	}
	//! ��ӦEV_TXEMPTY�¼�
	virtual void OnTxEmpty()
	{
		Notify(ON_COM_TXEMPTY);
	}
	//! ��ӦEV_ERROR�¼�
	virtual void OnError()
	{
		Notify(ON_COM_ERROR, ClearError());
	}
	//! ��ӦEV_RING�¼�
	virtual void OnRing()
	{
		Notify(ON_COM_RING, CheckRING() ? 1 : 0);
	}
	//! ��ӦEV_RLSD�¼�
	virtual void OnRLSD()
	{
		Notify(ON_COM_RLSD, CheckRLSD() ? 1 : 0);
	}
	//! ��ӦEV_RXFLAG�¼�
	virtual void OnRxFlag()
	{
		Notify(ON_COM_RXFLAG);
	}
	//! ��ӦEV_POWER�¼�
	virtual void OnPower()
	{
		Notify(ON_COM_POWER);
	}
	//! ��ӦEV_RX80FULL�¼�
	virtual void OnRx80Full()
	{
		Notify(ON_COM_RX80FULL);
	}
	//! ��ӦEV_EVENT1�¼�
	virtual void OnEvent1()
	{
		Notify(ON_COM_EVENT1);
	}
	//! ��ӦEV_EVENT2�¼�
	virtual void OnEvent2()
	{
		Notify(ON_COM_EVENT2);
	}
	//! ��ӦEV_PERR�¼�
	virtual void OnPrintErr()
	{
		Notify(ON_COM_PERR);
	}
	//! ͨ�õ��¼�����
	virtual void HandleEvent(DWORD dwMask)
	{
		if ((dwMask & EV_RXCHAR) && !(dwOption_&EN_RX_THREAD))
		{
			DWORD dwLength = GetQueueCount(true);

			if (dwLength)
			{
				if (dwOption_ & EN_RX_BUFFER)
				{
					PortToBuffer((dwLength << 1) + 64);//������ֽ��� ���������¼���϶������

					if (I_.Size() >= dwNotifyNum_)
						OnReceive();
				}
				else
				{
					if (dwLength >= dwNotifyNum_)
						OnReceive();
				}
			}
		}

		if (dwMask & EV_TXEMPTY)
		{
			if ((dwOption_&EN_TX_BUFFER) && !(dwOption_&EN_TX_THREAD) && O_.SafeSize())
				BufferToPort();

			OnTxEmpty();
		}

		if (dwMask & EV_RXFLAG)
			OnRxFlag();

		if (dwMask & EV_CTS)
			OnCTS();
			
		if (dwMask & EV_DSR)
			OnDSR();
			
		if (dwMask & EV_RING)
			OnRing();
			
		if (dwMask & EV_RLSD)
			OnRLSD();
			
		if (dwMask & EV_BREAK)
			OnBreak();
			
		if (dwMask & EV_ERR)
			OnError();

	#ifdef CN_COMM_FOR_CE
		if (dwMask & EV_POWER)
			OnPower();
	#endif
	}
	
#ifndef CN_COMM_FOR_CE
	//! �����߳������ص�I/Oģ�� 
	virtual DWORD OverlappedModel()
	{
		if(!CN_ASSERT(IsOpen()))
			return 1;

		if(!CN_ASSERT(::SetCommMask(hComm_, dwWaitEvent_)))
			return 1;

		for(DWORD dwMask = 0, dwLength; bContinue_ && IsOpen(); dwMask = 0)
		{
			if (GetQueueCount(true))//! �ȴ��¼�ǰ����ɨ������Ƿ���δ�������� �����ģ��һ��EV_RXCHAR�¼� �����¼�֪ͨ������
				dwMask = EV_RXCHAR, Sleep(10);
			else
			{
				if(!::WaitCommEvent(hComm_, &dwMask, &EO_))
				{
					if(::GetLastError() == ERROR_IO_PENDING)
						::GetOverlappedResult(hComm_, &EO_, &dwLength, TRUE);
					else
					{
						Sleep(10);
						continue;
					}
				}
			}
			
			if(dwMask == 0)
			{
				if ((dwOption_&EN_TX_BUFFER) && !(dwOption_&EN_TX_THREAD) && O_.SafeSize())
					BufferToPort();

				continue;
			}
			
			HandleEvent(dwMask);
		}//for

		return 0;
	}
#endif
	//! �����߳���������I/Oģ�� 
	virtual DWORD NonoverlappedModel()
	{
		if(!CN_ASSERT(IsOpen()))
			return 1;

		for (DWORD dwReturn; bContinue_ && IsOpen();)
		{
			dwReturn = WaitForSingleObject(hWatchEvent_, 50);

			if (!bContinue_) 
				break;

			switch (dwReturn)
			{
			case WAIT_OBJECT_0:
				while ((dwOption_&EN_TX_BUFFER) && O_.SafeSize())
					BufferToPort();

				ResetEvent(hWatchEvent_);

				break;

			case WAIT_TIMEOUT:

				DWORD dwLength = GetQueueCount(true);

				if (dwLength)
				{
					if (dwOption_ & EN_RX_BUFFER)
					{
						PortToBuffer(dwLength);

						if (I_.Size() >= dwNotifyNum_)
							OnReceive();
					}
					else
					{
						if (dwLength >= dwNotifyNum_)
							OnReceive();
					}
				}

				if ( (dwOption_&EN_TX_BUFFER) && O_.SafeSize() )
					BufferToPort();

				break;
			}
		}

		return 0;
	}
#ifdef CN_COMM_FOR_CE
	//! �����߳�����WINCE��I/Oģ��(�ص�+���� Ҳ��֪΢��������ʲôģʽ)
	virtual DWORD EmbeddedModel()
	{
		if(!CN_ASSERT(IsOpen()))
			return 1;

		if(!CN_ASSERT(::SetCommMask(hComm_, dwWaitEvent_)))
			return 1;

		for(DWORD dwMask = 0; bContinue_ && IsOpen(); dwMask = 0)
		{
			if (GetQueueCount(true))//! �ȴ��¼�ǰ����ɨ������Ƿ���δ�������� �����ģ��һ��EV_RXCHAR�¼� �����¼�֪ͨ������
				dwMask = EV_RXCHAR, Sleep(10);
			else
			{
				if(!::WaitCommEvent(hComm_, &dwMask, NULL))
					continue;
			}
			
			if(dwMask == 0)
			{
				if ( (dwOption_&EN_TX_BUFFER) && !(dwOption_&EN_TX_THREAD) && O_.SafeSize())
					BufferToPort();

				continue;
			}
		
			HandleEvent(dwMask);

		}//for

		return 0;
	}
#endif
	//! ����˫��������Ȼ�����Ըı���; 
	virtual DWORD ReadModel()
	{
		while(bContinue_)
		{
			Sleep(50);

			DWORD dwLength = GetQueueCount(true);

			if (dwLength)
			{
				if (dwOption_ & EN_RX_BUFFER)
				{
					PortToBuffer(dwLength);

					if (I_.Size() >= dwNotifyNum_)
						OnReceive();
				}
				else
				{
					if (dwLength >= dwNotifyNum_)
						OnReceive();
				}
			}
		}

		return 0;
	}
	//! ����˫��������Ȼ�����Ըı���; 
	virtual DWORD WriteModel()
	{
		CN_ASSERT(dwOption_ & EN_TX_BUFFER);

		while (bContinue_)
		{
			DWORD dwReturn = ::WaitForSingleObject(hWriteEvent_, 200);

			while(bContinue_ && O_.SafeSize())
				BufferToPort();

			if (dwReturn == WAIT_OBJECT_0)
				ResetEvent(hWriteEvent_);
		}

		return 0;
	}
	
private:  
	//! ��ֹ��������
	CnComm(const CnComm&);
	//! ��ֹ��ֵ����
	CnComm &operator = (const CnComm&);

#if defined(_MT) && !defined(CN_COMM_FOR_CE)
	//! �����߳� Watch Thread ��ɼ��� ���������þ����Ƿ���ɶ�д
	static UINT APIENTRY WatchThreadProc(LPVOID lpPara)
#else
	//! �����߳� Watch Thread ��ɼ��� ���������þ����Ƿ���ɶ�д
	static DWORD WINAPI WatchThreadProc(LPVOID lpPara)
#endif
	{
	#ifdef CN_COMM_FOR_CE 
		DWORD dwCode = ((CnComm *)lpPara)->EmbeddedModel();
	#else
		DWORD dwCode = ((CnComm *)lpPara)->IsOverlappedMode() 
			? ((CnComm *)lpPara)->OverlappedModel() 
			: ((CnComm *)lpPara)->NonoverlappedModel();

		#if defined(_MT) 
			_endthreadex(dwCode);
		#endif
	#endif

		return dwCode;
	}

#if defined(_MT) && !defined(CN_COMM_FOR_CE)
	//! ˫�����߳� ��ʱδ�� �����ò���
	static UINT APIENTRY ReadThreadProc(LPVOID lpPara)
#else
	//! ˫�����߳� ��ʱδ�� �����ò���
	static DWORD WINAPI ReadThreadProc(LPVOID lpPara)
#endif
	{
		DWORD dwCode = ((CnComm *)lpPara)->ReadModel();

		#if defined(_MT) && !defined(CN_COMM_FOR_CE)
			_endthreadex(dwCode);
		#endif

		return dwCode;
	}

#if defined(_MT) && !defined(CN_COMM_FOR_CE)
	//! ˫�����߳� WINCE���Բ���
	static UINT APIENTRY WriteThreadProc(LPVOID lpPara)
#else 
	//! ˫�����߳� WINCE���Բ���
	static DWORD WINAPI WriteThreadProc(LPVOID lpPara)
#endif
	{
		DWORD dwCode = ((CnComm *)lpPara)->WriteModel();

		#if defined(_MT) && !defined(CN_COMM_FOR_CE)
			_endthreadex(dwCode);
		#endif

		return dwCode;
	}
};

#endif //! _CN_COMM_H_
