VERSION 5.00
Begin VB.Form 三个数的最大值 
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
      Caption         =   "清零"
      Height          =   255
      Left            =   2160
      TabIndex        =   8
      Top             =   120
      Width           =   615
   End
   Begin VB.CommandButton Command1 
      Caption         =   "计算"
      Height          =   2175
      Left            =   4080
      TabIndex        =   5
      Top             =   600
      Width           =   375
   End
   Begin VB.TextBox Text3 
      Height          =   495
      Left            =   2760
      TabIndex        =   2
      Top             =   480
      Width           =   1095
   End
   Begin VB.TextBox Text2 
      Height          =   495
      Left            =   1560
      TabIndex        =   1
      Top             =   480
      Width           =   1095
   End
   Begin VB.TextBox Text1 
      Height          =   495
      Left            =   360
      TabIndex        =   0
      Top             =   480
      Width           =   1095
   End
   Begin VB.Label Label4 
      Caption         =   "王梓宁"
      Height          =   255
      Left            =   3000
      TabIndex        =   7
      Top             =   120
      Width           =   1455
   End
   Begin VB.Label Label3 
      Height          =   735
      Left            =   240
      TabIndex        =   6
      Top             =   2040
      Width           =   3495
   End
   Begin VB.Label Label2 
      Alignment       =   2  'Center
      Caption         =   "最大数为"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   26.25
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   615
      Left            =   240
      TabIndex        =   4
      Top             =   1080
      Width           =   3615
   End
   Begin VB.Label Label1 
      Caption         =   "请输入3个数"
      Height          =   255
      Left            =   240
      TabIndex        =   3
      Top             =   120
      Width           =   1575
   End
End
Attribute VB_Name = "三个数的最大值"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
a = Val(Text1.Text)
b = Val(Text2.Text)
c = Val(Text3.Text)
If a > b Then
    If a > c Then
        Label3.Caption = a
    Else
        Label3.Caption = c
    End If
End If
If b > a Then
    If b > c Then
        Label3.Caption = b
    Else
        Label3.Caption = c
    End If
End If
End Sub

Private Sub Command2_Click()
Text1.Text = ""
Text2.Text = ""
Text3.Text = ""
Label3.Caption = ""
End Sub
