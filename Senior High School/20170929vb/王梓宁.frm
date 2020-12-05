VERSION 5.00
Begin VB.Form Form1 
   BackColor       =   &H00FFFFFF&
   Caption         =   "计算器"
   ClientHeight    =   3030
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   4560
   LinkTopic       =   "Form1"
   ScaleHeight     =   3030
   ScaleWidth      =   4560
   StartUpPosition =   3  '窗口缺省
   Begin VB.CommandButton Command12 
      Caption         =   "C"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   12
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   615
      Left            =   2880
      TabIndex        =   15
      Top             =   1800
      Width           =   495
   End
   Begin VB.CommandButton Command11 
      Caption         =   "="
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   12
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   1335
      Left            =   3600
      TabIndex        =   13
      Top             =   1080
      Width           =   495
   End
   Begin VB.CommandButton Command10 
      Caption         =   "+"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   12
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   255
      Left            =   2880
      TabIndex        =   11
      Top             =   1080
      Width           =   495
   End
   Begin VB.CommandButton Command0 
      Caption         =   "0"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   12
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   255
      Left            =   1320
      TabIndex        =   10
      Top             =   2160
      Width           =   495
   End
   Begin VB.CommandButton Command9 
      Caption         =   "9"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   12
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   255
      Left            =   2040
      TabIndex        =   9
      Top             =   1800
      Width           =   495
   End
   Begin VB.CommandButton Command8 
      Caption         =   "8"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   12
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   255
      Left            =   1320
      TabIndex        =   8
      Top             =   1800
      Width           =   495
   End
   Begin VB.CommandButton Command7 
      Caption         =   "7"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   12
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   255
      Left            =   480
      TabIndex        =   7
      Top             =   1800
      Width           =   495
   End
   Begin VB.CommandButton Command6 
      Caption         =   "6"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   12
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   255
      Left            =   2040
      TabIndex        =   6
      Top             =   1440
      Width           =   495
   End
   Begin VB.CommandButton Command5 
      Caption         =   "5"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   12
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   255
      Left            =   1320
      TabIndex        =   5
      Top             =   1440
      Width           =   495
   End
   Begin VB.CommandButton Command4 
      Caption         =   "4"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   12
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   255
      Left            =   480
      TabIndex        =   4
      Top             =   1440
      Width           =   495
   End
   Begin VB.CommandButton Command3 
      Caption         =   "3"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   12
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   255
      Left            =   2040
      TabIndex        =   3
      Top             =   1080
      Width           =   495
   End
   Begin VB.CommandButton Command2 
      Caption         =   "2"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   12
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   255
      Left            =   1320
      TabIndex        =   2
      Top             =   1080
      Width           =   495
   End
   Begin VB.CommandButton Command1 
      Caption         =   "1"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   12
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   255
      Left            =   480
      TabIndex        =   1
      Top             =   1080
      Width           =   495
   End
   Begin VB.Label Label4 
      Caption         =   "王梓宁"
      Height          =   375
      Left            =   0
      TabIndex        =   16
      Top             =   2640
      Width           =   1455
   End
   Begin VB.Label Label3 
      Alignment       =   1  'Right Justify
      BackStyle       =   0  'Transparent
      Height          =   135
      Left            =   4200
      TabIndex        =   14
      Top             =   600
      Width           =   135
   End
   Begin VB.Label Label2 
      Alignment       =   1  'Right Justify
      BackColor       =   &H00FFFFFF&
      BackStyle       =   0  'Transparent
      Height          =   255
      Left            =   3480
      TabIndex        =   12
      Top             =   480
      Width           =   855
   End
   Begin VB.Label Label1 
      Alignment       =   1  'Right Justify
      BackColor       =   &H00FFFFFF&
      BorderStyle     =   1  'Fixed Single
      Height          =   735
      Left            =   480
      TabIndex        =   0
      Top             =   120
      Width           =   3855
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
Label1.Caption = Label1.Caption & 1
End Sub

Private Sub Command0_Click()
Label1.Caption = Label1.Caption & 0
End Sub

Private Sub Command10_Click()
Label3.Caption = "+"
Label2.Caption = Label1.Caption
Label1.Caption = ""
End Sub

Private Sub Command11_Click()
aa = Val(Label1.Caption)
bb = Val(Label2.Caption)
Label1.Caption = aa + bb
Label2.Caption = ""
Label3.Caption = ""
End Sub

Private Sub Command12_Click()
Label1.Caption = ""
Label2.Caption = ""
Label3.Caption = ""
End Sub

Private Sub Command2_Click()
Label1.Caption = Label1.Caption & 2
End Sub

Private Sub Command3_Click()
Label1.Caption = Label1.Caption & 3
End Sub

Private Sub Command4_Click()
Label1.Caption = Label1.Caption & 4
End Sub

Private Sub Command5_Click()
Label1.Caption = Label1.Caption & 5
End Sub

Private Sub Command6_Click()
Label1.Caption = Label1.Caption & 6
End Sub

Private Sub Command7_Click()
Label1.Caption = Label1.Caption & 7
End Sub

Private Sub Command8_Click()
Label1.Caption = Label1.Caption & 8
End Sub

Private Sub Command9_Click()
Label1.Caption = Label1.Caption & 9
End Sub

Private Sub Text1_Change()

End Sub
