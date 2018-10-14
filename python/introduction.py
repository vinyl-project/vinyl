import pyvinyl as pv
import os
import time
import math

# 脚本结束
def exit_script():
    pv.message_box("脚本演示结束，最好的脚本永远是您自己制作的。 :-)")


# 例子:关闭当前窗口
# 说明:Windows里面按下alt+f4即可关闭当前窗口,模拟这个操作
def close_window():
    pv.key_down("alt")
    pv.key_press("f4")
    pv.key_up("alt")

# 例子:用鼠标画一个圆
def draw_circle():
    r=300
    x0=512
    y0=384
    x=0
    y=0
    n=0
    while n<3.1415926*2:
        x=x0+r*math.cos(n)
        y=y0-r*math.sin(n)
        pv.move_to(int(x), int(y))
        pv.sleep(20)
        n=n+0.03

# 点击编辑界面的注释按钮，即可看到比较详细的脚本说明
pv.DELAY = 0
pv.cmd("notepad")
pv.sleep(2000)
StringDelay = 1000
# 最大化写字板
pv.key_down(pv.KeyCode.LeftAlt)
pv.key_down(pv.KeyCode.Space)
pv.sleep(500)
pv.key_press(pv.KeyCode.X)
pv.sleep(500)
pv.key_up(pv.KeyCode.Space)
pv.key_up(pv.KeyCode.LeftAlt)

pv.say_string("hi，你好，我是<按键精灵>，我是个很有趣的软件，如果你愿意花5分钟的时间来了解我，你一定会喜欢上我的。 :-)")
pv.key_press(pv.KeyCode.Enter)

pv.sleep(StringDelay)
pv.say_string("愿意了解我吗？如果愿意，请你按下键盘上的Y键，如果不喜欢我，那就按下键盘上的N键（等待按键...）")
pv.key_press("Enter")


while True:
    # 等待按键
    key = pv.KeyCode.NoneKey
    if (pv.is_key_down(pv.KeyCode.Y)):
        key = pv.KeyCode.Y

    if (pv.is_key_down(pv.KeyCode.N)):
        key = pv.KeyCode.N
    
    if (key != pv.KeyCode.NoneKey):
        pv.key_press("Enter")
        if key == pv.KeyCode.N:
            close_window()
            # 按下n不保存，直接关闭
            pv.sleep(1000)
            pv.key_press("N")
            pv.sleep(1000)
            exit_script()
        elif key == pv.KeyCode.Y:
            break
        else:
            pv.say_string("请按Y或者N，不要按其他键(等待按键...)")
            pv.key_press("Enter")



#结束等待
pv.say_string("哈哈，我太高兴了，又多了一个喜欢我的朋友，那我先来一个自我介绍吧。")
pv.key_press("Enter")
pv.sleep(StringDelay)
pv.say_string("我叫“按键精灵”，我的爸爸是伟大的兄弟工作组，我在网上有个家，地址是www.anjian.com，欢迎来做客哦")
pv.key_press("Enter")
pv.sleep(StringDelay)
# pv.say_string("嗯，好像废话多了些，如果不希望我继续废话，请按一下键盘，随便哪个键都可以啦（等待按键空格...）")
pv.say_string("嗯，好像废话多了些，如果不希望我继续废话，请按一下空格（等待按空格...）")
pv.key_press("Enter")
# TODO
pv.wait_key("Space")
pv.key_press("Enter")
pv.say_string("嘿嘿，按键了吧。其实我的本领就是让你按一下键盘，就可以作很多动作。不过你好像还有点不太理解哦")
pv.key_press("Enter")
pv.sleep(StringDelay)
pv.say_string("嗯")
for i in range(6):
    pv.say_string(".")
    pv.sleep(500)

pv.say_string("让我想想怎么解释给你")
for i in range(6):
    pv.say_string(".")
    pv.sleep(500)



pv.key_press("Enter")
# pv.say_string("哈，有了，我把一些好朋友使用我的例子介绍给你吧，想听的话就再按一下键盘吧（等待按键...）")
pv.say_string("哈，有了，我把一些好朋友使用我的例子介绍给你吧，想听的话就再按一下空格吧（等待按空格...）")
pv.key_press("Enter")
# TODO
pv.wait_key("Space")
pv.key_press("Enter")
pv.say_string("呵呵，其实我最多的朋友是玩游戏的朋友，特别是玩网络游戏的朋友。")
pv.key_press("Enter")
pv.sleep(StringDelay)
pv.say_string("在游戏里，经常要做一些重复的动作，比如反复按鼠标和键盘，有了我就轻松啦，我可以代替你按键盘和鼠标。")
pv.key_press("Enter")
pv.sleep(StringDelay)
pv.say_string("我还很聪明的，只要你稍微熟悉我一些，就可以让我作出很多聪明的动作，比如在游戏里面自动找怪物打怪物。")
pv.key_press("Enter")
pv.sleep(StringDelay)
pv.say_string("由于我只是模仿人们双手的操作，所以我和那些万恶的外挂是坚决划清界限的，大家一定要支持我啊")
pv.key_press("Enter")
pv.sleep(StringDelay)
pv.say_string("除了玩家之外，我还有很多朋友，比如有的把我当作日常办公的小助手，减轻了很多工作，可惜不给我发工资。")
pv.key_press("Enter")
pv.sleep(StringDelay)
pv.say_string("总之，我很有用啦，双手可以做到的事情，我都可以代劳，如果你发现有些事情双手做起来很累，就交给我吧！")
pv.key_press("Enter")
pv.key_press("Enter")
pv.sleep(StringDelay)
pv.say_string("啊，罗嗦了很多啦，下面我还是手把手的告诉你一些我的具体能力吧。")
pv.key_press("Enter")
pv.sleep(StringDelay)
pv.say_string("先把我的废话都清空，嘻嘻，随便按一个键看我本事吧（等待按空格...）")
pv.key_press("Enter")
# TODO
pv.wait_key("Space")
pv.key_press("Enter")
pv.say_string("注意看哦，我接下来会自动按下""alt+e""进入写字板的""编辑""菜单，然后再按下a全选我的废话，再按del清空")
pv.key_press("Enter")
pv.sleep(StringDelay)
pv.sleep(StringDelay)
pv.say_string("倒计时，3、")
pv.sleep(StringDelay)
pv.say_string("2、")
pv.sleep(StringDelay)
pv.say_string("1")
pv.sleep(StringDelay)
pv.key_down("LeftAlt")
pv.key_press("E")
pv.key_up("LeftAlt")
pv.sleep(StringDelay)
pv.key_press("A")
pv.sleep(StringDelay)
pv.key_press("Delete")
pv.sleep(StringDelay)
#第二步
pv.key_press("Enter")
pv.say_string("呼..... 整个世界清净了，下面我先介绍一下我的基本能力：模拟键盘和鼠标")
pv.key_press("Enter")
pv.sleep(StringDelay)
pv.say_string("先按下一下a键，注意了，这可不是我说出来的a，是我模拟按出来的哦")
pv.key_press("Enter")
pv.sleep(StringDelay)
pv.key_press("Enter")
pv.key_press("A")
pv.key_press("Enter")
pv.key_press("Enter")
pv.say_string("看明白了吗？好像不是很明显，那我按3下a键")
pv.key_press("Enter")
pv.sleep(StringDelay)
pv.key_press("Enter")
for i in range(3):
    pv.key_press("A")
pv.key_press("Enter")
pv.key_press("Enter")
pv.say_string("这下是不是更清楚了呢？我再多按一些")
pv.key_press("Enter")
pv.sleep(StringDelay)
pv.key_press("Enter")
pv.key_press("A")
pv.key_press("B")
pv.key_press("C")
pv.key_press("D")
pv.key_press("E")
pv.key_press("F")
pv.key_press("G")
pv.key_press("H")
pv.key_press("Enter")
pv.key_press("Enter")
pv.say_string("哈，这下看清了吧？上面这些字母都是我模拟键盘按下去的。")
pv.key_press("Enter")
pv.sleep(StringDelay)
pv.say_string("我还会按 组合键 呢，我现在按一下ctrl+a，这样可以把我的废话全部选中")
pv.key_press("Enter")
pv.sleep(StringDelay)
pv.key_down("LeftControl")
pv.key_press("A")
pv.key_up("LeftControl")
pv.sleep(StringDelay)
pv.key_press("End")
pv.say_string("哈哈，看到了吧？我厉害吧？下面介绍一下模拟鼠标，这个动作可复杂了，是套组合动作")
pv.key_press("Enter")
pv.sleep(StringDelay)
# pv.say_string("想让我演示的话就按一下键盘吧（等待按键...）")
pv.say_string("想让我演示的话就按一下空格吧（等待按键...）")
pv.key_press("Enter")
pv.sleep(StringDelay)
# TODO
pv.wait_key("Space")
pv.key_press("Enter")
pv.say_string("我先用鼠标画一个圆，然后把鼠标移动到屏幕中间，保存一下鼠标的位置，然后按下右键，")
pv.key_press("Enter")
pv.say_string("再向左平移一些，再按下左键，然后再把鼠标恢复到中间的位置")
pv.key_press("Enter")
pv.sleep(StringDelay)
pv.say_string("是不是看起来很复杂？我用慢动作表演一下，注意开始喽")
pv.key_press("Enter")
pv.key_press("Enter")
pv.sleep(StringDelay)


# 第三步
draw_circle()
pv.sleep(1000)
intX,intY = pv.size()
pv.move_to(0,0)
pv.sleep(StringDelay)
pv.move_to(intX//2,intY//2)
# SaveMousePos 
ox,oy = pv.position()

pv.sleep(StringDelay)
pv.right_click()
pv.sleep(StringDelay)
pv.move(-20,0)
pv.sleep(StringDelay)
pv.left_click()
pv.sleep(StringDelay)
# RestoreMousePos 
pv.move_to(ox,oy)
pv.sleep(StringDelay)
pv.key_down("LeftControl")
pv.key_press("End")
pv.key_up("LeftControl")
pv.say_string("有没有看晕呢？呵呵。其实我演示了我模拟鼠标的基本能力，那就是")
pv.key_press("Enter")
pv.say_string("鼠标点击、鼠标移动、鼠标相对移动和保存/恢复鼠标位置，当然中间还加了一些\"延时\"")
pv.sleep(StringDelay)
pv.key_press("Enter")
pv.key_press("Enter")
pv.say_string("好了，基本的本领介绍完了，你可以使用我的编辑功能制作这些动作，全是界面操作，非常非常简单，快去试试吧！")
pv.sleep(StringDelay)
end_script()

