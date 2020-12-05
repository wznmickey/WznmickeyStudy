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
      Left            =   120
      TabIndex        =   2
      Top             =   240
      Width           =   2295
   End
   Begin VB.CommandButton Command1 
      Caption         =   "计算"
      Height          =   975
      Left            =   2640
      TabIndex        =   0
      Top             =   1680
      Width           =   1695
   End
   Begin VB.Label Label2 
      Height          =   375
      Left            =   3000
      TabIndex        =   3
      Top             =   1080
      Width           =   975
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      Caption         =   "1-1000中的素数 作业2 王梓宁"
      Height          =   600
      Left            =   3000
      TabIndex        =   1
      Top             =   360
      Width           =   1335
      WordWrap        =   -1  'True
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
s = 0
For i = 2 To 1000
    bool = True
    For j = 2 To Int(Sqr(i))
        If i Mod j = 0 Then
            bool = False
            Exit For
        End If
    Next j
    If bool = True Then
        List1.AddItem i
        s = s + 1
    End If
Next i
List1.AddItem "共" & s & "个"
Label2.Caption = "共" & s & "个"
End Sub
