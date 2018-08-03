
// Canon TestDlg.h : ͷ�ļ�
//

#pragma once


// CCanonTestDlg �Ի���
class CCanonTestDlg : public CDialogEx
{
// ����
public:
	CCanonTestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CANONTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnShot();
	CComboBox m_Av;
	CComboBox m_Iso;
	CComboBox m_Tv;
	afx_msg void OnCbnSelchangeComboIso();
	afx_msg void OnCbnSelchangeComboAv();
	afx_msg void OnCbnSelchangeComboTv();
	afx_msg void OnBnClickedButtonEnd();
	afx_msg void OnBnClickedButtonStart();
	
	static UINT ThreadPhotograph(LPVOID ThreaParam);
	CDC *pDC;
	CRect rect;
	long ts[10];
	long tt[10];
	
	afx_msg void OnBnClickedButtonStopview();
};
