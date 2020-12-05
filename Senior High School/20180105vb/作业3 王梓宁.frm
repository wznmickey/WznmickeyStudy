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
   Begin VB.TextBox Text2 
      Height          =   495
      Left            =   2640
      TabIndex        =   4
      Top             =   1920
      Width           =   1575
   End
   Begin VB.TextBox Text1 
      Height          =   495
      Left            =   2760
      TabIndex        =   2
      Top             =   840
      Width           =   1575
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Command1"
      Height          =   495
      Left            =   3240
      TabIndex        =   0
      Top             =   2520
      Width           =   1095
   End
   Begin VB.Label Label4 
      Caption         =   "输入第2个整数"
      Height          =   255
      Left            =   2760
      TabIndex        =   3
      Top             =   1560
      Width           =   1455
   End
   Begin VB.Label Label3 
      Caption         =   "输入第1个整数"
      Height          =   255
      Left            =   2880
      TabIndex        =   1
      Top             =   240
      Width           =   1455
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Private Sub Command1_Click()
 Dim t1 As Integer, t2 As Integer, i As Integer, n As Integer
 Dim f As Single                           'f为存储华氏温度值
 t1 = Val(Text1.Text)
 t2 = Val(Text2.Text)
 If t1 > t2 Then   '下划线部分为补充代码位置，补充后删除下划线
   n = t1: t1 = t2: t2 = n
 End If
 i = t1
 Print "   摄氏温度    华氏温度 "
 Print
 Do While i <= t2 '下划线部分为补充代码位置，补充后删除下划线
   f = i * 9 / 5 + 32
   Print "   "; i; "          "; f '下划线部分为补充代码位置，补充后删除下划线
 i = i + 1
 Loop
End Sub


'注意：每空只能写一个表达式或者一行语句，不能修改其它语句。

