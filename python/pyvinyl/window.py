import pyvinyl
import pyvinyl.vinyl
from pyvinyl.mouse import ButtonCode
from pyvinyl.keyboard import KeyCode

class Window():
	def __init__(self, handle):
		self.win = handle

	def size(self):
		return pyvinyl.vinyl.get_window_size(self.win)
	
	def screenshot(self, x, y, w, h):
		image = pyvinyl.vinyl.screenshot(self.win, x, y, w, h)
		return image[:,:,::-1]

	def message_box(self, content):
		pyvinyl.vinyl.message_box(self.win, content)
		if (pyvinyl.DELAY > 0):
			pyvinyl.sleep(pyvinyl.DELAY)

	def say_string(self, text):
		pyvinyl.auto_delay()
		pyvinyl.vinyl.say_string(self.win, text)

	def mouse_pos(self):
		return pyvinyl.vinyl.get_mouse_pos(self.win)

	def mouse_move(self, x=None, y=None, duration=0):
		pyvinyl.auto_delay()
		
		if (x == None):
			x = 0
		if (y == None):
			y = 0

		pyvinyl.vinyl.mouse_move(self.win, x, y)
	
	def mouse_move_to(self, x=None, y=None, duration=0):
		pyvinyl.auto_delay()

		if (x==None or y==None):
			pos = pyvinyl.position()			
			if (x == None):
				x = pos[0]
			if (y == None):
				y = pos[1]

		pyvinyl.vinyl.mouse_move_to(self.win, x, y)

	def wait_key(self, code):
		if (type(code) == KeyCode):
			while(pyvinyl.vinyl.is_key_up(self.win, code)):
				pass
		elif (type(code) == str):
			while(pyvinyl.vinyl.is_key_up(self.win, KeyCode[code].value)):
				pass

	def is_key_up(self, code):
		result = False
		if (type(code) == KeyCode):
			result = pyvinyl.vinyl.is_key_up(self.win, code.value)
		elif (type(code) == str):
			result = pyvinyl.vinyl.is_key_up(self.win, KeyCode[code].value)
		return result

	def is_key_down(self, code):
		result = False
		if (type(code) == KeyCode):
			result = pyvinyl.vinyl.is_key_down(self.win, code.value)
		elif (type(code) == str):
			result = pyvinyl.vinyl.is_key_down(self.win, KeyCode[code].value)
		return result  

	def key_down(self, code):
		pyvinyl.auto_delay()

		if (type(code) == KeyCode):
			pyvinyl.vinyl.key_down(self.win, code.value)
		elif (type(code) == str):
			pyvinyl.vinyl.key_down(self.win, KeyCode[code].value)
		

	def key_up(self, code):
		pyvinyl.auto_delay()

		if (type(code) == KeyCode):
			pyvinyl.vinyl.key_up(self.win, code.value)
		elif (type(code) == str):
			pyvinyl.vinyl.key_up(self.win, KeyCode[code].value)
		

	def key_press(self, code):
		pyvinyl.auto_delay()

		if (type(code) == KeyCode):
			pyvinyl.vinyl.key_click(self.win, code.value)
		elif (type(code) == str):
			pyvinyl.vinyl.key_click(self.win, KeyCode[code].value)

	def hotkey(self, *args):
		pyvinyl.auto_delay()
		for key in args:
			pyvinyl.key_down(self.win, key)

		args = args[::-1]
		for key in args:
			pyvinyl.key_up(self.win, key)

	def is_button_up(self, code):
	    result = False
	    if (type(code) == ButtonCode):
	        result = pyvinyl.vinyl.is_mouse_button_up(self.win, code.value)
	    elif (type(code) == str):
	        result = pyvinyl.vinyl.is_mouse_button_up(self.win, ButtonCode[code].value)
	    return result
	
	def is_button_down(self, code):
	    result = False
	    if (type(code) == ButtonCode):
	        result = pyvinyl.vinyl.is_mouse_button_down(self.win, code.value)
	    elif (type(code) == str):
	        result = pyvinyl.vinyl.is_mouse_button_down(self.win, ButtonCode[code].value)
	    return result
	
	def click(self, x=None, y=None, clicks=1, interval=0, button='Left'):
	    pyvinyl.auto_delay()
	
	    pos = pyvinyl.position()
	    if (x == None):
	        x = pos[0]
	    if (y == None):
	        y = pos[1]
	    if (x!=None or y!=None):
	        pyvinyl.vinyl.move_to(x, y)
	    
	    clicks_num = 0
	    while(clicks_num<clicks):
	        if(ButtonCode[button] == ButtonCode.Left):
	            pyvinyl.vinyl.left_click(self.win)
	        elif(ButtonCode[button] == ButtonCode.Right):
	            pyvinyl.vinyl.right_click(self.win)
	        elif(ButtonCode[button] == ButtonCode.Middle):
	            pyvinyl.vinyl.middle_click(self.win)
	        
	        if(interval>0):
	            pyvinyl.sleep(interval)
	        clicks_num = clicks_num + 1	

	def left_down(self):
	    pyvinyl.auto_delay()
	    pyvinyl.vinyl.left_down(self.win)
	
	def middle_down(self):
	    pyvinyl.auto_delay()
	    pyvinyl.vinyl.middle_down(self.win)
	
	def right_down(self):
	    pyvinyl.auto_delay()
	    pyvinyl.vinyl.right_down(self.win)

	def left_up(self):
	    pyvinyl.auto_delay()
	    pyvinyl.vinyl.left_up(self.win)
	
	def middle_up(self):
	    pyvinyl.auto_delay()
	    pyvinyl.vinyl.middle_up(self.win)
	
	def right_up(self):
	    pyvinyl.auto_delay()
	    pyvinyl.vinyl.right_up(self.win)

	def left_click(self):
	    pyvinyl.auto_delay()
	    pyvinyl.vinyl.left_click(self.win)
	
	def middle_click(self):
	    pyvinyl.auto_delay()
	    pyvinyl.vinyl.middle_click(self.win)
	
	def right_click(self):
	    pyvinyl.auto_delay()
	    pyvinyl.vinyl.right_click(self.win)

	def left_double_click(self, interval=200):
	    pyvinyl.auto_delay()
	
	    pyvinyl.vinyl.left_click(self.win)
	    pyvinyl.vinyl.sleep(interval)
	    pyvinyl.vinyl.left_click(self.win)
	
	def middle_double_click(self, interval=200):
	    pyvinyl.auto_delay()
	
	    pyvinyl.vinyl.middle_click(self.win)
	    pyvinyl.vinyl.sleep(interval)
	    pyvinyl.vinyl.middle_click(self.win)
	
	def right_double_click(self, interval=200):
	    pyvinyl.auto_delay()
	
	    pyvinyl.vinyl.right_click(self.win)
	    pyvinyl.vinyl.sleep(interval)
	    pyvinyl.vinyl.right_click(self.win)
	
	def mouse_up(self, x=None,y=None,button='Left'):
	    pyvinyl.auto_delay()
	
	    pos = pyvinyl.position()
	    if (x == None):
	        x = pos[0]
	    if (y == None):
	        y = pos[1]
	    if (x!=None or y!=None):
	        pyvinyl.vinyl.move_to(self.win, x, y)
	
	    if(ButtonCode[button] == ButtonCode.Left):
	        pyvinyl.vinyl.left_up(self.win)
	    elif(ButtonCode[button] == ButtonCode.Right):
	        pyvinyl.vinyl.right_up(self.win)
	    elif(ButtonCode[button] == ButtonCode.Middle):
	        pyvinyl.vinyl.middle_up(self.win)	
	
	def mouse_down(self, x=None,y=None,button='Left'):
	    pyvinyl.auto_delay()
	
	    pos = pyvinyl.position()
	    if (x == None):
	        x = pos[0]
	    if (y == None):
	        y = pos[1]
	    if (x!=None or y!=None):
	        pyvinyl.vinyl.move_to(self.win, x, y)
	
	    if(ButtonCode[button] == ButtonCode.Left):
	        pyvinyl.vinyl.left_down(self.win)
	    elif(ButtonCode[button] == ButtonCode.Right):
	        pyvinyl.vinyl.right_down(self.win)
	    elif(ButtonCode[button] == ButtonCode.Middle):
	        pyvinyl.vinyl.middle_down(self.win)	
	
	def scroll(self, delta, x=None,y=None):
	    pyvinyl.auto_delay()
	
	    pos = pyvinyl.position()
	    if (x == None):
	        x = pos[0]
	    if (y == None):
	        y = pos[1]
	    if (x!=None or y!=None):
	        pyvinyl.vinyl.move_to(self.win, x, y)
	
	    pyvinyl.vinyl.mouse_wheel(self.win, delta)

def new_window(path):
	win = pyvinyl.vinyl.new_window(path);
	if win == None:
		return None;

	return pyvinyl.Window(win)

def window_from_pos(x=None, y=None):
	win = pyvinyl.vinyl.find_window_from_pos(x, y);
	if win == None:
		return None;

	return pyvinyl.Window(win)

def window_from_tile(tile):
	win = pyvinyl.vinyl.find_window_from_tile(tile);
	if win == None:
		return None;

	return pyvinyl.Window(win)

def window_from_classname(classname):
	win = pyvinyl.vinyl.find_window_from_classname(classname);
	if win == None:
		return None;

	return pyvinyl.Window(win)