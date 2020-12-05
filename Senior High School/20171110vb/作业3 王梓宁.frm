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
      Caption         =   "打印"
      Height          =   375
      Left            =   2760
      TabIndex        =   0
      Top             =   480
      Width           =   1575
   End
   Begin VB.Label Label1 
      Caption         =   "王梓宁"
      Height          =   1695
      Left            =   3120
      TabIndex        =   1
      Top             =   1320
      Width           =   855
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
i = 1
Do While i <= 10
    j = 1
    Do While j <= 10
        Print "*";
        j = j + 1
    Loop
    Print "这是第";
    Print i;
    Print "行"
    i = i + 1
Loop

End Sub

