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
   Begin VB.ListBox List1 
      Height          =   2400
      Left            =   3240
      TabIndex        =   0
      Top             =   240
      Width           =   1095
   End
   Begin VB.Label Label1 
      Caption         =   "王梓宁"
      Height          =   255
      Left            =   120
      TabIndex        =   1
      Top             =   120
      Width           =   1095
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim score As Double: Dim i As Integer: Dim s As Integer: Dim max As Integer: Dim min As Integer
Private Sub Form_Load()
score = 0
i = 0
s = 0
max = -5
min = 105
Do While score <> -1
score = InputBox("请输入成绩,输入-1结束")
If score >= 0 And score <= 100 Then
i = i + 1
s = s + score
List1.AddItem score
If score < min Then
min = score
End If
If score > max Then
max = score
End If
Else
    If score <> -1 Then
    MsgBox ("请输入正确数据,输入-1结束")
    End If
End If
Loop
End Sub

Private Sub Label3_Click()

End Sub

Private Sub Label4_Click()

End Sub
