VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   9420
   ClientLeft      =   4620
   ClientTop       =   1470
   ClientWidth     =   19755
   Icon            =   "作业1 王梓宁.frx":0000
   LinkTopic       =   "Form1"
   MinButton       =   0   'False
   ScaleHeight     =   10000
   ScaleMode       =   0  'User
   ScaleWidth      =   20751.05
   Begin VB.ListBox List1 
      Height          =   5460
      ItemData        =   "作业1 王梓宁.frx":038A
      Left            =   360
      List            =   "作业1 王梓宁.frx":038C
      TabIndex        =   11
      Top             =   360
      Width           =   855
   End
   Begin VB.CommandButton Command5 
      Caption         =   "逆序"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   42
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   1935
      Left            =   5520
      TabIndex        =   10
      Top             =   1320
      Width           =   6375
   End
   Begin VB.TextBox Text1 
      Height          =   270
      Left            =   5520
      TabIndex        =   8
      Top             =   4440
      Width           =   5775
   End
   Begin VB.CommandButton Command1 
      Caption         =   "重新输入"
      Height          =   855
      Left            =   5520
      TabIndex        =   7
      Top             =   3480
      Width           =   6375
   End
   Begin VB.ListBox List2 
      Height          =   5460
      ItemData        =   "作业1 王梓宁.frx":038E
      Left            =   3360
      List            =   "作业1 王梓宁.frx":0390
      TabIndex        =   3
      Top             =   360
      Width           =   855
   End
   Begin VB.CommandButton Command2 
      Caption         =   "清除"
      Height          =   735
      Left            =   4440
      TabIndex        =   2
      Top             =   5040
      Width           =   8535
   End
   Begin VB.CommandButton Command3 
      Caption         =   "升序"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   42
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   3495
      Left            =   4440
      TabIndex        =   1
      Top             =   1320
      Width           =   975
   End
   Begin VB.CommandButton Command4 
      Caption         =   "降序"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   42
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   3615
      Left            =   12120
      TabIndex        =   0
      Top             =   1320
      Width           =   975
   End
   Begin VB.Label Label4 
      Alignment       =   2  'Center
      AutoSize        =   -1  'True
      Caption         =   "个数"
      Height          =   255
      Left            =   11400
      TabIndex        =   9
      Top             =   4440
      Width           =   615
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      AutoSize        =   -1  'True
      Caption         =   "作业1 王梓宁"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   36
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   720
      Left            =   4530
      TabIndex        =   6
      Top             =   360
      Width           =   9915
      WordWrap        =   -1  'True
   End
   Begin VB.Label Label2 
      Alignment       =   2  'Center
      Caption         =   "输入"
      Height          =   255
      Left            =   240
      TabIndex        =   5
      Top             =   6120
      Width           =   855
   End
   Begin VB.Label Label3 
      Alignment       =   2  'Center
      Caption         =   "输出"
      Height          =   255
      Left            =   3360
      TabIndex        =   4
      Top             =   6120
      Width           =   855
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim a(1 To 1000) As Long, b(1 To 1000) As Long, z As Long, y As Long, j As Long, n As Long
Private Sub sort(ByVal Left As Long, ByVal Right As Long)
Dim Mid As Long, l As Long, r As Long
If Left >= Right Then Exit Sub
l = Left
r = Right
Mid = (Left + Right) \ 2
Do While (l <= r) And (l <= Right) And (r >= Left)
    Do While a(l) < a(Mid)
        l = l + 1
        If l > Right Then Exit Do
    Loop
    Do While a(r) > a(Mid)
        r = r - 1
        If r < Left Then Exit Do
    Loop
    If l <= r Then
        t = a(l)
        a(l) = a(r)
        a(r) = t
        l = l + 1
        r = r - 1
    End If
Loop
If r < Right Then Call sort(Left, r)
If l > Left Then Call sort(l, Right)
End Sub
Private Sub nixu()
For i = 1 To n \ 2
    t = a(n + 1 - i)
    a(n + 1 - i) = a(i)
    a(i) = t
Next i
End Sub
Private Sub shuchu()
List2.Clear
For i = 1 To n
    List2.AddItem a(i)
Next i
End Sub
Private Sub Command1_Click()
List1.Clear
List2.Clear
n = Val(Text1.Text)
Call personinput
End Sub
Private Sub Command2_Click()
List2.Clear
End Sub
Private Sub Command3_Click()
z = 1
y = n
Call chushihua
Call sort(z, y)
Call shuchu
End Sub
Private Sub Command4_Click()
z = 1
y = n
Call chushihua
Call sort(z, y)
Call nixu
Call shuchu
End Sub
Private Sub Command5_Click()
Call chushihua
Call nixu
Call shuchu
End Sub
Private Sub chushihua()
For i = 1 To n
    a(i) = b(i)
Next i
End Sub
Private Sub personinput()
List1.Clear
i = 1
For i = 1 To n
    a(i) = InputBox("请输入" & n & "个整数：第" & i & "个")
    b(i) = a(i)
    List1.AddItem a(i)
Next i
End Sub
Private Sub Form_Load()
Text1.Text = 10
n = Text1.Text
Call personinput
End Sub
