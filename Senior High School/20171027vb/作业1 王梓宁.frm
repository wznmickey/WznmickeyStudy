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
   Begin VB.TextBox Text4 
      Alignment       =   1  'Right Justify
      Height          =   270
      Left            =   1800
      TabIndex        =   9
      Text            =   "2"
      Top             =   2640
      Width           =   1695
   End
   Begin VB.CommandButton Command2 
      Caption         =   "清除"
      Height          =   615
      Left            =   120
      TabIndex        =   6
      Top             =   840
      Width           =   1215
   End
   Begin VB.CommandButton Command1 
      Caption         =   "计算"
      Height          =   1095
      Left            =   3120
      TabIndex        =   4
      Top             =   240
      Width           =   1335
   End
   Begin VB.TextBox Text3 
      Height          =   375
      Left            =   1560
      TabIndex        =   2
      Top             =   1080
      Width           =   1455
   End
   Begin VB.TextBox Text2 
      Height          =   375
      Left            =   1560
      TabIndex        =   1
      Top             =   600
      Width           =   1455
   End
   Begin VB.TextBox Text1 
      Height          =   390
      Left            =   1560
      TabIndex        =   0
      Top             =   120
      Width           =   1455
   End
   Begin VB.Label Label5 
      Caption         =   "位"
      Height          =   495
      Left            =   3600
      TabIndex        =   10
      Top             =   2640
      Width           =   615
   End
   Begin VB.Label Label4 
      Caption         =   "你想保留几位？默认为2位（自动舍去小数点后的最后位的零）请保证总位数小于15"
      Height          =   1335
      Left            =   120
      TabIndex        =   8
      Top             =   1680
      Width           =   1455
   End
   Begin VB.Label Label3 
      BackStyle       =   0  'Transparent
      Caption         =   "面积是"
      Height          =   375
      Left            =   1680
      TabIndex        =   7
      Top             =   1680
      Width           =   4215
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      Height          =   540
      Left            =   2520
      TabIndex        =   5
      Top             =   1680
      Width           =   1935
   End
   Begin VB.Label Label1 
      Caption         =   "请输入三条边： 王梓宁"
      Height          =   375
      Left            =   120
      TabIndex        =   3
      Top             =   240
      Width           =   1335
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim p As Double: Dim s As Double

Private Sub Command1_Click()
a = Val(Text1.Text)
b = Val(Text2.Text)
c = Val(Text3.Text)
Label2.Caption = "面积是"
z = True
If ((a > b + c) Or (b > a + c) Or (c > a + b)) Then
MsgBox ("你认为这可以拼成一个三角形？请重新输入。")
z = False
End If
If (a <= 0) Or (b <= 0) Or (c <= 0) Then
MsgBox ("你认为三角形的边长可以是负数？请重新输入。")
z = False
End If
If (Int(Text4.Text) <> Text4.Text) Or (Text4.Text < 0) Then
MsgBox ("有这样的位数吗？请重新输入。")
z = False
End If
If (z = True) Then
p = a + b + c
p = p / 2
w = Val(Text4.Text)
s = Int(Sqr(p * (p - a) * (p - b) * (p - c)) * 10 ^ w + 0.5) / 10 ^ w
Label2.Caption = s
End If
End Sub

Private Sub Command2_Click()
Text1.Text = ""
Text2.Text = ""
Text3.Text = ""
Label2.Caption = ""
Text4.Text = "2"
End Sub

