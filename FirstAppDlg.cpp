// FirstAppDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FirstApp.h"
#include "FirstAppDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CFirstAppDlg dialog




CFirstAppDlg::CFirstAppDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFirstAppDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFirstAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFirstAppDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CFirstAppDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CFirstAppDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CFirstAppDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CFirstAppDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CFirstAppDlg message handlers

BOOL CFirstAppDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFirstAppDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFirstAppDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}
struct demoType{
	char name[20];
	char address[60];
};
CFile file;
// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFirstAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CFirstAppDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	file.Open(("C:\\test\\demoFile.txt"),CFile::modeCreate);
	file.Close();
	AfxMessageBox("Text File Created!");
}

void CFirstAppDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	struct demoType data;
	file.Open(("C:\\test\\demoFile.txt"),CFile::modeWrite);
	int x=sizeof(data.name);
	int y=sizeof(data.address);
	memset(&data.name,0,x);
	memset(&data.address,0,y);
	memcpy(&data.name,"Nishant",7);	
	memcpy(&data.address,"Jogiwala,Dehradun,UK",20);
	CString msg;
	msg.Format("Structure's Data Written in the file!");
	AfxMessageBox(msg);
	file.Write(&data,sizeof(demoType));	
	file.Close();
}
struct demoType in;
void CFirstAppDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	file.Open("C:\\test\\demoFile.txt",CFile::modeRead);
	//
	memset(&in,0,sizeof(demoType));
	int len=file.GetLength();
	file.Read(&in,len);
	//CString msg;
	//msg.Format("%d",len);
	AfxMessageBox("File's data has been read and copied to the struture!");
	file.Close();
}

void CFirstAppDlg::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
		
	file.Open(("C:\\test\\newFile.txt"),CFile::modeCreate|CFile::modeWrite);
	int x=sizeof(in.name);
	int y=sizeof(in.address);
	file.Write(&in,sizeof(demoType));
	CString msg;
	msg.Format("Structure's Data Written in the newFile!");
	AfxMessageBox(msg);
	file.Close();
}
