VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "王梓宁"
   ClientHeight    =   3030
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   4560
   BeginProperty Font 
      Name            =   "宋体"
      Size            =   24
      Charset         =   134
      Weight          =   400
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   LinkTopic       =   "Form1"
   ScaleHeight     =   3030
   ScaleWidth      =   4560
   StartUpPosition =   3  '窗口缺省
   Begin VB.CommandButton Command2 
      Caption         =   "交换"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   855
      Left            =   2880
      TabIndex        =   5
      ToolTipText     =   "交换"
      Top             =   2040
      Width           =   1455
   End
   Begin VB.CommandButton Command1 
      Caption         =   "="
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   18
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   120
      TabIndex        =   4
      ToolTipText     =   "等于"
      Top             =   1080
      Width           =   1335
   End
   Begin VB.TextBox Text2 
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   21.75
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00008000&
      Height          =   915
      Left            =   2880
      TabIndex        =   1
      Top             =   120
      Width           =   1500
   End
   Begin VB.TextBox Text1 
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   21.75
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000FF&
      Height          =   915
      Left            =   120
      TabIndex        =   0
      Top             =   120
      Width           =   1500
   End
   Begin VB.Label Label3 
      Alignment       =   2  'Center
      BackColor       =   &H8000000D&
      Caption         =   "王梓宁"
      BeginProperty Font 
         Name            =   "楷体"
         Size            =   24
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   -1  'True
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   240
      MousePointer    =   5  'Size
      TabIndex        =   6
      ToolTipText     =   "王梓宁"
      Top             =   2400
      Width           =   2505
   End
   Begin VB.Label Label2 
      BackColor       =   &H00FFFFFF&
      BorderStyle     =   1  'Fixed Single
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   15.75
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00800000&
      Height          =   735
      Left            =   120
      TabIndex        =   3
      Top             =   1560
      Width           =   2655
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      BackStyle       =   0  'Transparent
      Caption         =   "÷"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   21.75
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   975
      Left            =   1680
      TabIndex        =   2
      Top             =   240
      Width           =   1095
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim a As Double, b As Long, c As Long
Private Sub Command1_Click()
b = Text1.Text
c = Text2.Text
a = b / c
Label2.Caption = Format(a, "0.0000000000")
End Sub

Private Sub Command2_Click()
st = Text1.Text
Text1.Text = Text2.Text
Text2.Text = st
co = Text1.ForeColor
Text1.ForeColor = Text2.ForeColor
Text2.ForeColor = co
End Sub

