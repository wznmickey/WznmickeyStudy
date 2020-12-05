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
   Begin VB.CommandButton Command2 
      Caption         =   "清除"
      Height          =   375
      Left            =   2280
      TabIndex        =   3
      Top             =   1560
      Width           =   2175
   End
   Begin VB.CommandButton Command1 
      Caption         =   "计算"
      Height          =   735
      Left            =   2280
      TabIndex        =   2
      Top             =   2040
      Width           =   2175
   End
   Begin VB.ListBox List1 
      Height          =   1680
      Left            =   360
      TabIndex        =   1
      Top             =   480
      Width           =   1815
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "作业2 王梓宁"
      Height          =   1095
      Left            =   2280
      TabIndex        =   0
      Top             =   360
      Width           =   2175
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim bool As Boolean
Private Sub Command1_Click()
If bool = True Then
    MsgBox ("自动清除之前内容")
    List1.Clear
    bool = False
End If
bool = True
List1.AddItem "作业1  王梓宁"
List1.AddItem 4656736
End Sub

Private Sub Command2_Click()
List1.Clear
bool = False
End Sub

Private Sub Form_Load()
bool = False
End Sub

