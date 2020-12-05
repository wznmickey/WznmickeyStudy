VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "作业2 王梓宁"
   ClientHeight    =   3030
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   4560
   ForeColor       =   &H00000000&
   LinkTopic       =   "Form1"
   ScaleHeight     =   3030
   ScaleWidth      =   4560
   StartUpPosition =   3  '窗口缺省
   Begin VB.CommandButton Command2 
      Caption         =   "清除"
      Height          =   650
      Left            =   3840
      TabIndex        =   5
      ToolTipText     =   "清除无法撤销，请谨慎思考"
      Top             =   2280
      Width           =   615
   End
   Begin VB.CommandButton Command1 
      Caption         =   "确定"
      Height          =   650
      Left            =   2040
      TabIndex        =   4
      ToolTipText     =   "按下按钮，等第立即出现"
      Top             =   2280
      Width           =   1575
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
      Height          =   1455
      Left            =   120
      MultiLine       =   -1  'True
      TabIndex        =   2
      ToolTipText     =   "输入你的成绩获取你的等第，快行动吧"
      Top             =   1440
      Width           =   1335
   End
   Begin VB.Label Label3 
      Caption         =   "你的等第是..."
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   15.75
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   1095
      Left            =   1560
      TabIndex        =   3
      Top             =   1440
      Width           =   2895
   End
   Begin VB.Label Label2 
      Alignment       =   2  'Center
      Caption         =   "请输入分数（0-100）"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   21.75
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   735
      Left            =   120
      TabIndex        =   1
      Top             =   480
      Width           =   4335
   End
   Begin VB.Label Label1 
      Caption         =   "制作：王梓宁"
      Height          =   375
      Left            =   240
      TabIndex        =   0
      Top             =   120
      Width           =   1695
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
b = True
If Text1.Text = "" Then
b = False
End If
a = Val(Text1.Text)
If a < 0 Then
b = False
End If
If a > 100 Then
b = False
End If
If b = True Then
    If a < 60 Then
    Label3.Caption = "你的等第是不合格"
    Else
        If a < 80 Then
        Label3.Caption = "你的等第是合格"
        Else
            If a < 90 Then
            Label3.Caption = "你的等第是良好"
            Else
            Label3.Caption = "你的等第是优秀"
            End If
        End If
    End If
Else
    Label3.Caption = "你的等第是..."
    MsgBox ("请重新输入")
    Label3.Caption = "请重新输入，再次点击确定"
End If
End Sub

Private Sub Command2_Click()
Label3.Caption = "你的等第是..."
Text1.Text = ""
End Sub
