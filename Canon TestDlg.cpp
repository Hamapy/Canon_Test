
// Canon TestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Canon Test.h"
#include "Canon TestDlg.h"
#include "afxdialogex.h"
#include "EDSDK.h"
#include "EDSDKErrors.h"
#include "EDSDKTypes.h"
#include "Canon.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCanonTestDlg �Ի���




CCanonTestDlg::CCanonTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCanonTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	
}

void CCanonTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_AV, m_Av);
	DDX_Control(pDX, IDC_COMBO_ISO, m_Iso);
	DDX_Control(pDX, IDC_COMBO_TV, m_Tv);
}

BEGIN_MESSAGE_MAP(CCanonTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_SHOT, &CCanonTestDlg::OnBnClickedBtnShot)
	ON_CBN_SELCHANGE(IDC_COMBO_ISO, &CCanonTestDlg::OnCbnSelchangeComboIso)
	ON_CBN_SELCHANGE(IDC_COMBO_AV, &CCanonTestDlg::OnCbnSelchangeComboAv)
	ON_CBN_SELCHANGE(IDC_COMBO_TV, &CCanonTestDlg::OnCbnSelchangeComboTv)
	ON_BN_CLICKED(IDC_BUTTON_END, &CCanonTestDlg::OnBnClickedButtonEnd)
	ON_BN_CLICKED(IDC_BUTTON_START, &CCanonTestDlg::OnBnClickedButtonStart)
	ON_BN_CLICKED(IDC_BUTTON_STOPVIEW, &CCanonTestDlg::OnBnClickedButtonStopview)
END_MESSAGE_MAP()


// CCanonTestDlg ��Ϣ�������

BOOL CCanonTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��
	rect.left=200;
	rect.right=930;
	rect.top=11;
	rect.bottom=540;
	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CCanonTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCanonTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CCanonTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





void CCanonTestDlg::OnCbnSelchangeComboIso()
{
	int n  = m_Iso.GetCurSel();
	SetPropertyCommand(camera,kEdsPropID_ISOSpeed,Cameradata.IsoDesc[n+1]);
}


void CCanonTestDlg::OnCbnSelchangeComboAv()
{
	//CString strCBText;
	//m_Av.GetLBText(m_Av.GetCurSel(), strCBText);
	int n  = m_Av.GetCurSel();
	SetPropertyCommand(camera,kEdsPropID_Av,Cameradata.AvDesc[n+1]);	
}


void CCanonTestDlg::OnCbnSelchangeComboTv()
{
	int n  = m_Tv.GetCurSel();
	SetPropertyCommand(camera,kEdsPropID_Tv,Cameradata.TvDesc[n+1]);
}


void CCanonTestDlg::OnBnClickedButtonEnd()
{
	applicationEnd();
}


void CCanonTestDlg::OnBnClickedButtonStart()
{
	applicationRun();

	CString str;
	int num1=0,num2=0,num3=0;
	for(int i=1;i<Cameradata.AvDesc[0];i++)
	{
		//str.Format("%ld",Cameradata.AvDesc[i]);
		str=updateProperty(0,(EdsUInt32)Cameradata.AvDesc[i]);

		m_Av.InsertString(i-1, LPCTSTR(str));
		if(Cameradata.AvDesc[i]==Cameradata.curAv)num1=i;
			
	}
	for(int i=1;i<Cameradata.TvDesc[0];i++)
	{
		str=updateProperty(2,(EdsUInt32)Cameradata.TvDesc[i]);

		m_Tv.InsertString(i-1, LPCTSTR(str));
		if(Cameradata.TvDesc[i]==Cameradata.curTv)num2=i;
			
	}
	for(int i=1;i<Cameradata.IsoDesc[0];i++)
	{
		str=updateProperty(1,(EdsUInt32)Cameradata.IsoDesc[i]);
		m_Iso.InsertString(i-1, str);
		if(Cameradata.IsoDesc[i]==Cameradata.curIso)num3=i;
			
	}
	m_Tv.SetCurSel(num1);
	m_Iso.SetCurSel(num3);
	m_Av.SetCurSel(num2);
	UpdateData(FALSE);
}


UINT CCanonTestDlg::ThreadPhotograph(LPVOID ThreaParam)
{
	CCanonTestDlg *dlg=(CCanonTestDlg*)ThreaParam;
	while (Cameradata.isEvf)
	{
		//dlg->pDC=dlg->GetDC();
		if (Cameradata.isEvf==FALSE)
		{
			break;
		}
		DownloadEvfCommand(camera,dlg->pDC,dlg->rect);
	}
	dlg->ReleaseDC(dlg->pDC);
	EndEvfCommand(camera);
	return 0;
}
CWinThread *NIThread;
void CCanonTestDlg::OnBnClickedBtnShot()
{
	if (Cameradata.isOpenSession)
	{
		TakePictureCommand(camera);
	}
	else
	{
		MessageBox("������ĻỰδ��");
	}
}

void CCanonTestDlg::OnBnClickedButtonStopview()
{
	if (Cameradata.isOpenSession)
	{
		if (!Cameradata.isEvf)
		{
			Cameradata.isEvf=TRUE;
			Cameradata.isfinsh=false;
			StartEvfCommand(camera);
			pDC=GetDC();
			NIThread=AfxBeginThread(ThreadPhotograph,this,THREAD_PRIORITY_NORMAL,0,CREATE_SUSPENDED,NULL);
			NIThread->m_bAutoDelete=TRUE;
			NIThread->ResumeThread();
		}
		else
		{
			Cameradata.isEvf=FALSE;
			//NIThread->SuspendThread();
			//WaitForSingleObject(NIThread,INFINITE);
			//while(WaitForSingleObject(NIThread,5000)==WAIT_TIMEOUT);

			//ReleaseDC(pDC);
			//EndEvfCommand(camera);
		}
	}
	else
	{
		MessageBox("������ĻỰδ��");
	}
}
