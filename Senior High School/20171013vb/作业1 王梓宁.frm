VERSION 5.00
Begin VB.Form 计算圆的面积 
   BackColor       =   &H000000FF&
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
      Height          =   615
      Left            =   3120
      TabIndex        =   4
      Top             =   2280
      Width           =   1095
   End
   Begin VB.TextBox Text2 
      BackColor       =   &H00FFFFFF&
      Height          =   615
      Left            =   120
      MousePointer    =   3  'I-Beam
      TabIndex        =   3
      Top             =   1440
      Width           =   4215
   End
   Begin VB.TextBox Text1 
      BackColor       =   &H00FFFFFF&
      Height          =   975
      Left            =   2880
      MousePointer    =   3  'I-Beam
      MultiLine       =   -1  'True
      TabIndex        =   1
      Top             =   240
      Width           =   1575
   End
   Begin VB.Label Label3 
      BackColor       =   &H8000000D&
      Caption         =   "王梓宁 高一十三班"
      Height          =   735
      Left            =   120
      TabIndex        =   5
      Top             =   2280
      Width           =   2055
   End
   Begin VB.Label Label2 
      BackStyle       =   0  'Transparent
      Caption         =   "圆的面积是"
      BeginProperty Font 
         Name            =   "楷体"
         Size            =   24
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   120
      TabIndex        =   2
      Top             =   840
      Width           =   2655
   End
   Begin VB.Label Label1 
      BackColor       =   &H00FFFFFF&
      BackStyle       =   0  'Transparent
      Caption         =   "请输入圆的半径"
      BeginProperty Font 
         Name            =   "楷体"
         Size            =   18
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   120
      TabIndex        =   0
      Top             =   240
      Width           =   3375
   End
End
Attribute VB_Name = "计算圆的面积"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
Text2.Text = Text1.Text * 3.14 * Text1.Text
End Sub

