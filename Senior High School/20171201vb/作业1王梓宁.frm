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
      Caption         =   "清除"
      Height          =   975
      Left            =   2880
      TabIndex        =   8
      Top             =   1920
      Width           =   1575
   End
   Begin VB.CommandButton Command1 
      Caption         =   "计算"
      Height          =   735
      Left            =   1200
      TabIndex        =   7
      Top             =   2160
      Width           =   1455
   End
   Begin VB.TextBox Text2 
      Height          =   270
      Left            =   1200
      TabIndex        =   5
      Top             =   1440
      Width           =   3255
   End
   Begin VB.TextBox Text1 
      Height          =   270
      Left            =   1560
      TabIndex        =   3
      Top             =   120
      Width           =   2895
   End
   Begin VB.ListBox List1 
      Height          =   2580
      ItemData        =   "作业2王梓宁.frx":0000
      Left            =   120
      List            =   "作业2王梓宁.frx":0002
      TabIndex        =   1
      Top             =   360
      Width           =   975
   End
   Begin VB.Label Label4 
      AutoSize        =   -1  'True
      Caption         =   "键入回车结束"
      Height          =   180
      Left            =   1200
      TabIndex        =   6
      Top             =   1800
      Width           =   1080
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      Caption         =   "R1="
      Height          =   180
      Left            =   1200
      TabIndex        =   4
      Top             =   1200
      Width           =   270
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      Caption         =   "R总="
      Height          =   180
      Left            =   1200
      TabIndex        =   2
      Top             =   120
      Width           =   360
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      AutoSize        =   -1  'True
      Caption         =   "作业2王梓宁"
      Height          =   180
      Left            =   120
      TabIndex        =   0
      Top             =   120
      Width           =   1035
      WordWrap        =   -1  'True
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim i As Integer, r As Double
Private Sub Command1_Click()
If (Text2.Text <> "") Then
    If (Text2.Text > 0) Then
        MsgBox ("提示1：已自动加入当前输入数值")
        List1.AddItem Text2.Text
        i = i + 1
        Label3.Caption = "R" & i & "="
        r = r + 1 / Text2.Text
        Text2.Text = ""
    End If
End If
If r = 0 Then
    MsgBox ("错误2：电路未连接")
Else
    s = 1 / r
    Text1.Text = Format(s, "0.00")
End If
End Sub

Private Sub Command2_Click()
List1.Clear
Text1.Text = ""
Text2.Text = ""
i = 1
Label3.Caption = "R" & i & "="
End Sub

Private Sub Text2_KeyPress(KeyAscii As Integer)
If i = 0 Then
    i = 1
    r = 0
End If
If KeyAscii = 13 Then
    If Text2.Text <> "" Then
        If Text2.Text > 0 Then
            List1.AddItem Text2.Text
            i = i + 1
            Label3.Caption = "R" & i & "="
            r = r + 1 / Text2.Text
            Text2.Text = ""
        Else
            MsgBox ("错误1：你输入了错误的值")
            Text2.Text = ""
        End If
    Else
        MsgBox ("错误3：你未输入")
    End If
End If
End Sub
