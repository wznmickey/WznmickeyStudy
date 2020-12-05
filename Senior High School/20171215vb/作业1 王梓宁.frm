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
   Begin VB.CommandButton Command1 
      Caption         =   "计算"
      Height          =   975
      Left            =   1920
      TabIndex        =   2
      Top             =   1560
      Width           =   2175
   End
   Begin VB.ListBox List1 
      Height          =   1320
      Left            =   360
      TabIndex        =   1
      Top             =   840
      Width           =   1095
   End
   Begin VB.Label Label1 
      Caption         =   "计算100-999之间的水仙花数 作业1 王梓宁"
      Height          =   495
      Left            =   480
      TabIndex        =   0
      Top             =   240
      Width           =   2295
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
For i = 100 To 999
    n = i
    a = n Mod 10
    n = n \ 10
    b = n Mod 10
    c = n \ 10
    If a ^ 3 + b ^ 3 + c ^ 3 = i Then
        List1.AddItem i
    End If
Next i
'另一种方案
'For i = 1 To 9
'   For j = 0 To 9
'       For k = 0 To 9
'           n = i * 100 + j * 10 + k
'           If i ^ 3 + j ^ 3 + k ^ 3 = n Then List1.AddItem n
'       Next k
'   Next j
'Next i
End Sub
