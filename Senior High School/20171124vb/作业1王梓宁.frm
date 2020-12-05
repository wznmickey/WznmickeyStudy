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
      Caption         =   "1/(1/R1+1/R2)=?"
      Height          =   735
      Left            =   240
      TabIndex        =   7
      Top             =   1080
      Width           =   2895
   End
   Begin VB.TextBox Textr 
      Height          =   270
      Left            =   600
      TabIndex        =   6
      Top             =   2040
      Width           =   1935
   End
   Begin VB.TextBox Textr2 
      Height          =   270
      Left            =   600
      TabIndex        =   5
      Top             =   600
      Width           =   1935
   End
   Begin VB.TextBox Textr1 
      Height          =   270
      Left            =   600
      TabIndex        =   4
      Top             =   240
      Width           =   1935
   End
   Begin VB.Label Labelr 
      AutoSize        =   -1  'True
      Caption         =   "R="
      Height          =   180
      Left            =   240
      TabIndex        =   3
      Top             =   2040
      Width           =   180
   End
   Begin VB.Label Labelr2 
      AutoSize        =   -1  'True
      Caption         =   "R2="
      Height          =   180
      Left            =   240
      TabIndex        =   2
      Top             =   600
      Width           =   270
   End
   Begin VB.Label Labelr1 
      AutoSize        =   -1  'True
      Caption         =   "R1="
      Height          =   180
      Left            =   240
      TabIndex        =   1
      Top             =   240
      Width           =   270
   End
   Begin VB.Label Label1 
      Caption         =   "作业1王梓宁"
      Height          =   495
      Left            =   360
      TabIndex        =   0
      Top             =   2400
      Width           =   2775
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim r1 As Double, r2 As Double, r As Double
Private Sub Command1_Click()
r1 = Textr1.Text
r2 = Textr2.Text
r = 1 / r1 + 1 / r2
r = 1 / r
r = Format(r, "0.00")
Textr.Text = r
End Sub
