VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   3030
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   4560
   LinkTopic       =   "Form1"
   ScaleHeight     =   3030
   ScaleWidth      =   4560
   StartUpPosition =   3  '窗口缺省
   Begin VB.CommandButton Command2 
      Caption         =   "交换"
      Height          =   735
      Left            =   1200
      TabIndex        =   6
      Top             =   1800
      Width           =   2055
   End
   Begin VB.CommandButton Command1 
      Caption         =   "逆序"
      Height          =   735
      Left            =   1200
      TabIndex        =   5
      Top             =   960
      Width           =   2055
   End
   Begin VB.ListBox List2 
      Height          =   2220
      Left            =   3360
      TabIndex        =   1
      Top             =   360
      Width           =   855
   End
   Begin VB.ListBox List1 
      Height          =   2220
      Left            =   240
      TabIndex        =   0
      Top             =   360
      Width           =   855
   End
   Begin VB.Label Label3 
      Alignment       =   2  'Center
      Caption         =   "输出"
      Height          =   255
      Left            =   3360
      TabIndex        =   4
      Top             =   2640
      Width           =   855
   End
   Begin VB.Label Label2 
      Alignment       =   2  'Center
      Caption         =   "输入"
      Height          =   255
      Left            =   240
      TabIndex        =   3
      Top             =   2640
      Width           =   855
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "作业1 王梓宁"
      Height          =   375
      Left            =   1200
      TabIndex        =   2
      Top             =   480
      Width           =   2055
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim a(1 To 10) As Long, b(1 To 10) As Long
Private Sub Command1_Click()
List2.Clear
For i = 1 To 10
    b(i) = a(11 - i)
    List2.AddItem b(i)
Next i
End Sub

Private Sub Command2_Click()
List1.Clear
List2.Clear
For i = 1 To 10
    k = a(i)
    a(i) = b(i)
    b(i) = k
    List1.AddItem a(i)
    List2.AddItem b(i)
Next i
End Sub

Private Sub Form_Load()
For i = 1 To 10
    a(i) = InputBox("请输入10个正整数")
    List1.AddItem a(i)
Next i
End Sub
