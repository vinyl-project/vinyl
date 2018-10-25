import pyvinyl as pv
import os
import time
import math

# 脚本结束
def exit_script(win):
    win.message_box("脚本演示结束，最好的脚本永远是您自己制作的。 :-)")


# 例子:关闭当前窗口
# 说明:Windows里面按下alt+f4即可关闭当前窗口,模拟这个操作
def close_window(win):
    win.key_down("alt")
    win.key_press("f4")
    win.key_up("alt")

# 例子:用鼠标画一个圆
def draw_circle(win):
    r=300
    x0=512
    y0=384
    x=0
    y=0
    n=0
    while n<3.1415926*2:
        x=x0+r*math.cos(n)
        y=y0-r*math.sin(n)
        win.mouse_move_to(int(x), int(y))
        pv.sleep(20)
        n=n+0.03

# 点击编辑界面的注释按钮，即可看到比较详细的脚本说明
pv.DELAY = 0
win = pv.new_window("notepad")
pv.sleep(2000)
StringDelay = 1000
# 最大化写字板
win.key_down(pv.KeyCode.LeftAlt)
win.key_down(pv.KeyCode.Space)
pv.sleep(500)
win.key_press(pv.KeyCode.X)

pv.sleep(500)
win.key_up(pv.KeyCode.Space)
win.key_up(pv.KeyCode.LeftAlt)

win.say_string("hi，你好，我是<按键精灵>，我是个很有趣的软件，如果你愿意花5分钟的时间来了解我，你一定会喜欢上我的。 :-)\n", StringDelay)
win.say_string("愿意了解我吗？如果愿意，请你按下键盘上的Y键，如果不喜欢我，那就按下键盘上的N键（等待按键...）\n", StringDelay)

while True:
    # 等待按键
    key = pv.KeyCode.NoneKey
    if (win.is_key_down(pv.KeyCode.Y)):
        key = pv.KeyCode.Y

    if (win.is_key_down(pv.KeyCode.N)):
        key = pv.KeyCode.N
    
    if (key != pv.KeyCode.NoneKey):
        win.key_press("Enter")
        if key == pv.KeyCode.N:
            close_window(win)
            # 按下n不保存，直接关闭
            pv.sleep(1000)
            win.key_press("N", 1000)
            exit_script(win)
        elif key == pv.KeyCode.Y:
            break
        else:
            win.say_string("请按Y或者N，不要按其他键(等待按键...)\n")


#结束等待
win.say_string("\n哈哈，我太高兴了，又多了一个喜欢我的朋友，那我先来一个自我介绍吧。\n", StringDelay)
win.say_string("我叫“按键精灵”，我的爸爸是伟大的兄弟工作组，我在网上有个家，地址是www.vinyl.com，欢迎来做客哦\n", StringDelay)
win.say_string("嗯，好像废话多了些，如果不希望我继续废话，请按一下空格（等待按空格...）\n")
# TODO
win.wait_key("Space")
win.key_press("Enter")
win.say_string("嘿嘿，按键了吧。其实我的本领就是让你按一下键盘，就可以作很多动作。不过你好像还有点不太理解哦\n", StringDelay)
win.say_string("嗯")
for i in range(6):
    win.say_string(".", 500)

win.say_string("让我想想怎么解释给你")
for i in range(6):
    win.say_string(".", 500)

win.key_press("Enter")
win.say_string("哈，有了，我把一些好朋友使用我的例子介绍给你吧，想听的话就再按一下空格吧（等待按空格...）\n")
# TODO
win.wait_key("Space")
win.key_press("Enter")
win.say_string("呵呵，其实我最多的朋友是玩游戏的朋友，特别是玩网络游戏的朋友。\n", StringDelay)
win.say_string("在游戏里，经常要做一些重复的动作，比如反复按鼠标和键盘，有了我就轻松啦，我可以代替你按键盘和鼠标。\n", StringDelay)
win.say_string("我还很聪明的，只要你稍微熟悉我一些，就可以让我作出很多聪明的动作，比如在游戏里面自动找怪物打怪物。\n", StringDelay)
win.say_string("由于我只是模仿人们双手的操作，所以我和那些万恶的外挂是坚决划清界限的，大家一定要支持我啊\n", StringDelay)
win.say_string("除了玩家之外，我还有很多朋友，比如有的把我当作日常办公的小助手，减轻了很多工作，可惜不给我发工资。\n", StringDelay)
win.say_string("总之，我很有用啦，双手可以做到的事情，我都可以代劳，如果你发现有些事情双手做起来很累，就交给我吧！\n\n", StringDelay)
win.say_string("啊，罗嗦了很多啦，下面我还是手把手的告诉你一些我的具体能力吧。\n", StringDelay)
win.say_string("先把我的废话都清空，嘻嘻，随便按一个键看我本事吧（等待按空格...）\n")
# TODO
win.wait_key("Space")
win.key_press("Enter")
win.say_string("注意看哦，我接下来会自动按下""alt+e""进入写字板的""编辑""菜单，然后再按下a全选我的废话，再按del清空\n", StringDelay)
win.say_string("倒计时\n", StringDelay)
win.say_string("3\n", StringDelay)
win.say_string("2\n", StringDelay)
win.say_string("1\n", StringDelay)
win.key_down("LeftAlt")
win.key_press("E")
win.key_up("LeftAlt", StringDelay)
win.key_press("A", StringDelay)
win.key_press("Delete", StringDelay)
#第二步
win.key_press("Enter")
win.say_string("呼..... 整个世界清净了，下面我先介绍一下我的基本能力：模拟键盘和鼠标\n", StringDelay)
win.say_string("先按下一下a键，注意了，这可不是我说出来的a，是我模拟按出来的哦\n", StringDelay)
win.key_press("Enter")
win.key_press("A")
win.key_press("Enter")
win.key_press("Enter")
win.say_string("看明白了吗？好像不是很明显，那我按3下a键\n", StringDelay)
win.key_press("Enter")
for i in range(3):
    win.key_press("A")
win.key_press("Enter")
win.key_press("Enter")
win.say_string("\n这下是不是更清楚了呢？我再多按一些\n", StringDelay)
win.key_press("Enter")
win.key_press("A")
win.key_press("B")
win.key_press("C")
win.key_press("D")
win.key_press("E")
win.key_press("F")
win.key_press("G")
win.key_press("H")
win.key_press("Enter")
win.key_press("Enter")
win.say_string("哈，这下看清了吧？上面这些字母都是我模拟键盘按下去的。\n", StringDelay)
win.say_string("我还会按 组合键 呢，我现在按一下ctrl+a，这样可以把我的废话全部选中\n", StringDelay)
win.key_down("LeftControl")
win.key_press("A")
win.key_up("LeftControl", StringDelay)
win.key_press("End")
win.say_string("哈哈，看到了吧？我厉害吧？下面介绍一下模拟鼠标，这个动作可复杂了，是套组合动作\n",  StringDelay)
win.say_string("想让我演示的话就按一下空格吧（等待按键...）\n", StringDelay)
# TODO
win.wait_key("Space")
win.key_press("Enter")
win.say_string("我先用鼠标画一个圆，然后把鼠标移动到屏幕中间，保存一下鼠标的位置，然后按下右键，\n")
win.say_string("再向左平移一些，再按下左键，然后再把鼠标恢复到中间的位置\n", StringDelay)
win.say_string("是不是看起来很复杂？我用慢动作表演一下，注意开始喽\n\n", StringDelay)

# 第三步
draw_circle(win)
pv.sleep(1000)
intX,intY = win.size()
win.mouse_move_to(0,0)
pv.sleep(StringDelay)
win.mouse_move_to(intX//2,intY//2)
# SaveMousePos 
ox,oy = win.mouse_pos()

pv.sleep(StringDelay)
win.right_click(StringDelay)
win.mouse_move(-20,0)
pv.sleep(StringDelay)
win.left_click(StringDelay)
# RestoreMousePos 
win.mouse_move_to(ox,oy)
pv.sleep(StringDelay)
win.key_down("LeftControl")
win.key_press("End")
win.key_up("LeftControl")
win.say_string("有没有看晕呢？呵呵。其实我演示了我模拟鼠标的基本能力，那就是\n")
win.say_string("鼠标点击、鼠标移动、鼠标相对移动和保存/恢复鼠标位置，当然中间还加了一些\"延时\"\n\n", StringDelay)
win.say_string("好了，基本的本领介绍完了，你可以使用我的编辑功能制作这些动作，全是界面操作，非常非常简单，快去试试吧！\n", StringDelay)

exit_script(win)