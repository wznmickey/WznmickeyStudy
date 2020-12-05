VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   3195
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3195
   ScaleWidth      =   4680
   StartUpPosition =   3  '窗口缺省
   Begin VB.CommandButton Command1 
      Caption         =   "Command1"
      Height          =   615
      Left            =   3480
      TabIndex        =   2
      Top             =   2160
      Width           =   1095
   End
   Begin VB.TextBox Text2 
      Height          =   615
      Left            =   480
      TabIndex        =   1
      Top             =   2400
      Width           =   2175
   End
   Begin VB.TextBox Text1 
      Height          =   615
      Left            =   480
      TabIndex        =   0
      Top             =   1440
      Width           =   2295
   End
   Begin VB.Label Label1 
      Height          =   975
      Left            =   240
      TabIndex        =   3
      Top             =   240
      Width           =   4215
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
'1）函数Len（x）的功能：取字符串x的长度值（机字符个数值）。若x=“abc”，则Len（x）的值为3
'2）函数Mid（x,y,z）的功能：在字符串x中第y个字符开始取x个字符。若x=”zbcdefg”，则Mid（x,4,3）取得的值是def
'3）函数Asc（x）的功能：求字符x的ASCII码的数值。若x=”A”，则Asc（x）的值为65

Dim a As String, c As String, s As String
Dim I As Integer, b As Integer
a = Text1.Text  'a变量用于从第一个文本框内读取字符串值
b = Len(a)      'b变量用于存放字符串的长度值（即字符个数值）
'上面是定义变量和输入a值的正确代码，不必做修改
s = "": c = ""
For I = 1 To b '请在划线处填入正确的代码，然后删除下划线
   c = Mid(a, I, 1)
   If Asc(c) < 0 Or Asc(c) > 127 Then
     s = s + c
   End If
Next I

'以下是输出语句的正确代码，也不必做修改

Text2.Text = s  '将运算的结果写在第二个文本框内
End Sub

