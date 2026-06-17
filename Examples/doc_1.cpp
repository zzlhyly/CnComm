/*! \file doc_1.cpp  
	\brief ��������1 ������ʹ�ô���Ƭ�� �쳣����ʹ��Ƭ��
*/

#define CN_COMM_BUFFER_MIN_BLOCK_SIZE 512 //!<�ض��建������С
#define CN_COMM_STD_EXCEPTION
//#define CN_COMM_MFC_EXCEPTION
//#define CN_COMM_VCL_EXCEPTION

#include "..\Src\CnComm.h"

void TestException()
{
	try
	{
		CnComm Com;
		Com.Open(888);
	}
	catch (std::exception& e)
	{
		printf("%s", e.what());
	}
}

void TestBlockBuffer()
{
	char buf[1024] = {0};
	CnComm::BlockBuffer bb;
	
	bb.Write("0123456789");//д��10���ֽ� 
	bb.Read(buf, 5);//����5���ֽ� ������ʵ�ʶ�����
	bb.Clear();//���
	printf("%s\n", buf);

	char *pFree = (char*)bb.GetFreePtr(10);// ��ÿ��л�����
	strcpy(pFree, "0123456789");// д��10���ֽ� 
	bb.Release(10); // ����ʵ��ʹ�ô�С

	bb.Copy(buf, 5, 10); //�������� ƫ��10 5���ֽ� ���ݻ������ڻ�����
	bb.Read(NULL, 10);//ɾ��10���ֽ�
	printf("%s\n", buf);


	bb.Write("0123456789");
	bb.Read(buf, 10);//����bb.Copy(buf, 10, 0), bb.Read(0, 10);
	printf("%s\n", buf);
}

int main()
{
	TestException();
	TestBlockBuffer();
	return 0;
}
