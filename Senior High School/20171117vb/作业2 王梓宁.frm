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
   Begin VB.CommandButton Command3 
      Caption         =   "清除"
      Height          =   375
      Left            =   3120
      TabIndex        =   2
      Top             =   600
      Width           =   1335
   End
   Begin VB.CommandButton Command2 
      Caption         =   "打印正三角形"
      Height          =   375
      Left            =   3120
      TabIndex        =   1
      Top             =   120
      Width           =   1335
   End
   Begin VB.CommandButton Command1 
      Caption         =   "打印倒三角形"
      Height          =   375
      Left            =   3120
      TabIndex        =   0
      Top             =   1080
      Width           =   1335
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "王思源"
      BeginProperty Font 
         Name            =   "华文楷体"
         Size            =   14.25
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   615
      Left            =   3240
      TabIndex        =   3
      Top             =   2400
      Width           =   1335
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False


Private Sub Command1_Click()
n = 8
Do While n >= 1
Print Space(8 - n + 15);
j = 1
   Do While j <= 2 * n - 1
    Print "*";
    j = j + 1
   Loop
Print
n = n - 1
Loop
End Sub

Private Sub Command2_Click()
n = 8
For i = 1 To n
    Print Space(8 - i + 15);
    For j = 1 To 2 * i - 1
        Print "*";
    Next
    Print
Next
End Sub

Private Sub Command3_Click()
Cls
End Sub

