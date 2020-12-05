VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   2445
   ClientLeft      =   105
   ClientTop       =   435
   ClientWidth     =   9105
   LinkTopic       =   "Form1"
   ScaleHeight     =   2445
   ScaleWidth      =   9105
   StartUpPosition =   3  '窗口缺省
   Begin VB.TextBox Text2 
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   12
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   612
      Left            =   120
      TabIndex        =   2
      Top             =   1320
      Width           =   6252
   End
   Begin VB.TextBox Text1 
      Height          =   492
      Left            =   120
      TabIndex        =   1
      Text            =   "ADGDSFDSGFDFDJGFJHGLLGFHGFDSDFSGFFGFDSGHGHKJSDKGFDHFGGLKFSHGFSFGGFDJKHGFDJHGGHKJH:LLKJHL"
      Top             =   600
      Width           =   8892
   End
   Begin VB.CommandButton Command1 
      Caption         =   "运行"
      Height          =   612
      Left            =   6720
      TabIndex        =   0
      Top             =   1320
      Width           =   1572
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
Dim a As String, s As String
Dim i As Integer, j As Integer, b As Integer
a = Text1.Text     'a变量用于从第一个文本框内读取密文字符串值
b = Len(a)         'b变量用于存放密文字符串的长度值（即字符个数值）

'上面是定义变量和输入a值的正确代码，不必作修改

s = ""
For i = b To 1 Step -1
  s = s + Mid(a, i, 1)
Next i
a = s: s = ""
j = -2  '下划线部分为补充代码位置
For i = 1 To b Step 26
  j = j + 3
  s = s + Mid(a, i, j)
  i = i + j
Next i

'以下是输出语句的正确代码，也不必做修改

Text2.Text = s      '将运算的结果写在第二个文本框内

'程序调试正确后按试题要求将运行结果从文本框内复制填写到试卷指定位置

'最后请将调试正确的本工程文件保存在原来位置

End Sub

