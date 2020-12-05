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
      Height          =   1680
      Left            =   3480
      TabIndex        =   3
      Top             =   1200
      Width           =   975
   End
   Begin VB.Label Label3 
      Caption         =   "最大值"
      Height          =   615
      Left            =   120
      TabIndex        =   2
      Top             =   480
      Width           =   1575
   End
   Begin VB.Label Label2 
      Height          =   855
      Left            =   120
      TabIndex        =   1
      Top             =   1200
      Width           =   3135
   End
   Begin VB.Label Label1 
      Caption         =   "王梓宁"
      Height          =   735
      Left            =   3600
      TabIndex        =   0
      Top             =   360
      Width           =   855
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim i As Double
Dim max As Double
Dim n As Double
Dim a As Double
Private Sub Form_Load()
i = 1
max = InputBox("Please input a number 请输入1个数")
List1.AddItem max
n = 10 - 1
Do While i <= n
a = InputBox("Please input a number 请输入1个数")
List1.AddItem a
If max < a Then
max = a
End If
i = i + 1
Loop
Label2.Caption = max
End Sub

