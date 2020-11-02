VERSION 5.00
Object = "{BDC217C8-ED16-11CD-956C-0000C04E4C0A}#1.1#0"; "TABCTL32.OCX"
Begin VB.Form frmMain 
   Caption         =   "BinaryImage Sample1"
   ClientHeight    =   7152
   ClientLeft      =   60
   ClientTop       =   348
   ClientWidth     =   8340
   LinkTopic       =   "Form1"
   ScaleHeight     =   7152
   ScaleWidth      =   8340
   StartUpPosition =   3  'Windows Default
   Begin TabDlg.SSTab SSTab1 
      Height          =   6852
      Left            =   120
      TabIndex        =   0
      Top             =   120
      Width           =   8052
      _ExtentX        =   14203
      _ExtentY        =   12086
      _Version        =   393216
      Tabs            =   2
      Tab             =   1
      TabHeight       =   420
      TabCaption(0)   =   "Dot Language"
      TabPicture(0)   =   "frmMain.frx":0000
      Tab(0).ControlEnabled=   0   'False
      Tab(0).Control(0)=   "txtInput"
      Tab(0).Control(1)=   "labLogo"
      Tab(0).ControlCount=   2
      TabCaption(1)   =   "Picture"
      TabPicture(1)   =   "frmMain.frx":001C
      Tab(1).ControlEnabled=   -1  'True
      Tab(1).Control(0)=   "Label1"
      Tab(1).Control(0).Enabled=   0   'False
      Tab(1).Control(1)=   "Label2"
      Tab(1).Control(1).Enabled=   0   'False
      Tab(1).Control(2)=   "labScale"
      Tab(1).Control(2).Enabled=   0   'False
      Tab(1).Control(3)=   "cmdZoomOut"
      Tab(1).Control(3).Enabled=   0   'False
      Tab(1).Control(4)=   "cmdZoomIn"
      Tab(1).Control(4).Enabled=   0   'False
      Tab(1).Control(5)=   "PictureSource"
      Tab(1).Control(5).Enabled=   0   'False
      Tab(1).Control(6)=   "cmdExec"
      Tab(1).Control(6).Enabled=   0   'False
      Tab(1).Control(7)=   "PictureDestination"
      Tab(1).Control(7).Enabled=   0   'False
      Tab(1).Control(8)=   "cmdExit"
      Tab(1).Control(8).Enabled=   0   'False
      Tab(1).ControlCount=   9
      Begin VB.CommandButton cmdExit 
         Caption         =   "Exit"
         Height          =   252
         Left            =   360
         TabIndex        =   9
         Top             =   5880
         Width           =   1332
      End
      Begin VB.PictureBox PictureDestination 
         AutoSize        =   -1  'True
         Height          =   3372
         Left            =   3480
         ScaleHeight     =   277
         ScaleMode       =   3  'Pixel
         ScaleWidth      =   227
         TabIndex        =   8
         Top             =   960
         Width           =   2772
      End
      Begin VB.TextBox txtInput 
         Height          =   5772
         Left            =   -74880
         MultiLine       =   -1  'True
         ScrollBars      =   2  'Vertical
         TabIndex        =   7
         Text            =   "frmMain.frx":0038
         Top             =   360
         Width           =   7572
      End
      Begin VB.CommandButton cmdExec 
         Caption         =   "Start"
         Height          =   255
         Left            =   360
         TabIndex        =   4
         Top             =   4440
         Width           =   1335
      End
      Begin VB.PictureBox PictureSource 
         AutoSize        =   -1  'True
         Height          =   3372
         Left            =   360
         ScaleHeight     =   277
         ScaleMode       =   3  'Pixel
         ScaleWidth      =   227
         TabIndex        =   3
         Top             =   960
         Width           =   2772
      End
      Begin VB.CommandButton cmdZoomIn 
         Caption         =   "ZoomIn"
         Height          =   252
         Left            =   360
         TabIndex        =   2
         Top             =   4920
         Width           =   1332
      End
      Begin VB.CommandButton cmdZoomOut 
         Caption         =   "ZoomOut"
         Height          =   252
         Left            =   360
         TabIndex        =   1
         Top             =   5400
         Width           =   1332
      End
      Begin VB.Label labLogo 
         Caption         =   "C 2002 - 2003 oodTsen in Taiwan"
         BeginProperty Font 
            Name            =   "Verdana"
            Size            =   6
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   252
         Left            =   -69720
         TabIndex        =   11
         Top             =   6360
         Width           =   2412
      End
      Begin VB.Label labScale 
         Caption         =   "Scale :"
         BeginProperty Font 
            Name            =   "Verdana"
            Size            =   10.2
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   252
         Left            =   4560
         TabIndex        =   10
         Top             =   600
         Width           =   2652
      End
      Begin VB.Label Label2 
         Caption         =   "Distination"
         Height          =   252
         Left            =   3480
         TabIndex        =   6
         Top             =   600
         Width           =   2292
      End
      Begin VB.Label Label1 
         Caption         =   "Source"
         Height          =   252
         Left            =   360
         TabIndex        =   5
         Top             =   600
         Width           =   3492
      End
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Declare Function StretchBlt Lib "gdi32" (ByVal hdc As Long, ByVal x As Long, ByVal y As Long, ByVal nWidth As Long, ByVal nHeight As Long, ByVal hSrcDC As Long, ByVal xSrc As Long, ByVal ySrc As Long, ByVal nSrcWidth As Long, ByVal nSrcHeight As Long, ByVal dwRop As Long) As Long
Private m_width As Long
Private m_height As Long
Private scales

Private Sub cmdExec_Click()
    Dim dot
    Set dot = CreateObject("WINGRAPHVIZ.dot")
    
    If dot Is Nothing Then Exit Sub
    
    Dim img
    Set img = dot.ToEMF(txtInput.Text)
    
    If img Is Nothing Then Exit Sub
    
    Dim pic
    Set pic = img.Picture
    
    Set PictureDestination.Picture = pic
    Set PictureSource.Picture = pic
    
    m_width = PictureSource.width
    m_height = PictureSource.height
         
    Call SetMode
    
    Set pic = Nothing
    
    Set img = Nothing
    
    Set dot = Nothing
    
   
End Sub

Private Sub cmdExit_Click()
    Unload frmMain
End Sub

Private Sub cmdZoomIn_Click()
    If scales > 0.5 Then
        scales = scales / 2
        m_width = m_width / 2
        m_height = m_height / 2
        PictureDestination.width = m_width
        PictureDestination.height = m_height
           
    End If
    
    Call SetMode
End Sub

Private Sub cmdZoomOut_Click()
    If scales <= 1 Then
        scales = scales * 2
        m_width = m_width * 2
        m_height = m_height * 2
        PictureDestination.width = m_width
        PictureDestination.height = m_height
                
    End If
    
    Call SetMode
    
End Sub

Private Sub Form_Load()
    scales = 1
    
    cmdZoomIn.Enabled = False
    cmdZoomOut.Enabled = False
End Sub

Sub SetMode()
    If scales = 2 Then
        cmdZoomIn.Enabled = True
        cmdZoomOut.Enabled = False
    ElseIf scales = 0.5 Then
        cmdZoomIn.Enabled = False
        cmdZoomOut.Enabled = True
    Else
        cmdZoomIn.Enabled = True
        cmdZoomOut.Enabled = True
   
    End If
    
    labScale.Caption = "Scale : " + CStr(scales)
            
End Sub
