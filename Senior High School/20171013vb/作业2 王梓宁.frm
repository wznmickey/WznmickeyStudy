VERSION 5.00
Begin VB.Form 大小判断 
   BackColor       =   &H8000000D&
   Caption         =   "Form1"
   ClientHeight    =   3030
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   4560
   FillColor       =   &H00C00000&
   ForeColor       =   &H80000011&
   ScaleHeight     =   3030
   ScaleWidth      =   4560
   StartUpPosition =   3  '窗口缺省
   Begin VB.CommandButton Command1 
      Caption         =   "运行"
      Height          =   300
      Left            =   2640
      TabIndex        =   4
      Top             =   120
      Width           =   1695
   End
   Begin VB.TextBox Text3 
      Appearance      =   0  'Flat
      BackColor       =   &H8000000D&
      BorderStyle     =   0  'None
      Height          =   735
      Left            =   240
      TabIndex        =   3
      Top             =   2040
      Width           =   3975
   End
   Begin VB.TextBox Text2 
      Height          =   375
      Left            =   2520
      MousePointer    =   3  'I-Beam
      TabIndex        =   1
      Top             =   960
      Width           =   1695
   End
   Begin VB.TextBox Text1 
      Height          =   375
      Left            =   360
      MousePointer    =   3  'I-Beam
      TabIndex        =   0
      Top             =   960
      Width           =   1695
   End
   Begin VB.Label Label3 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "请输入2个实数"
      ForeColor       =   &H80000008&
      Height          =   735
      Left            =   360
      TabIndex        =   6
      Top             =   600
      Width           =   2775
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      Caption         =   "制作：王梓宁"
      Height          =   180
      Left            =   360
      TabIndex        =   5
      Top             =   120
      Width           =   1080
   End
   Begin VB.Label Label1 
      BackStyle       =   0  'Transparent
      Caption         =   "较大的数是"
      BeginProperty Font 
         Name            =   "新宋体"
         Size            =   21.75
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   -1  'True
         Strikethrough   =   0   'False
      EndProperty
      Height          =   615
      Left            =   240
      TabIndex        =   2
      Top             =   1560
      Width           =   4455
   End
End
Attribute VB_Name = "大小判断"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
If Val(Text1.Text) > Val(Text2.Text) Then
    Text3.Text = Val(Text1.Text)
Else
    Text3.Text = Val(Text2.Text)
End If
End Sub

