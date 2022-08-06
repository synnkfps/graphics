modes = {
    'basic1':['*','*', '*'], 
    'basic2':['#','#','#'],
    'basic3':[':',':',':'],
    'basic4':['~','-','~'],
    'mosaic1':[']', '[]','['],
    'mosaic2':['\\','|','/'],
    'mosaic3':[')', '|', '('],
    'mosaic4':['>', '|','<']
    }

mode_name = 'mosaic4'
mode = modes[mode_name]

size = 15
alt_size = size
contact = True
revert = False
gap = 1

border = True
border_char = '|'
border_title = 'graphics.py'

debug = True

if debug:
    print(f'SIZE={size}')
    print(f'GAP={gap}')
    print(f'BORDER={str(border).upper()}')
    if border:
        print(f'BORDER_CHAR="{border_char}"')
        if border_title != '':
            print(f'BORDER_TITLE="{border_title}"') 
def main():            
    global gap
    global size
    global alt_size

    check_border(size+(gap*2)+size, True)

    original_size = size
    for i in range(1, size+1):
        size -= 1
        char = mode[0]
        char2= mode[2]
        if i == original_size and contact == False:
            char = mode[1]
            char2= mode[1]

        print(border_char + char*i + ' '*((size+gap)*2) + char2*i + border_char)

    for k in range(1, alt_size):
        alt_size -= 1
        size += 1
        char = mode[2]
        char2= mode[0]
        if revert == False:
            char = mode[0]
            char2= mode[2]

        print(border_char + char*alt_size + ' '*((size+gap)*2) + char2*alt_size + border_char)

    check_border(gap, False)

def check_border(n, title=bool):
    global border_char
    window_up = []
    window_down=''
    counter = 0

    for i in '-'*(size+(gap*2)+size):
        window_up.append(i)

    if n == (size+(gap*2)+size) and (border_title != ''):
        for i,j in zip(window_up, border_title):
            counter += 1
            window_up[counter] = j
            continue

    if n == gap and (border_title != ''):
        for i in range(size+(gap*2)+size+2):
            window_down += '-'

    if border:
        border_char = '|'
        if n == size+(gap*2)+size:
            print('+' + ''.join(window_up) + '+')
        elif n == gap:
            print('+' + ''.join(window_down) + '+')
    else:
        border_char = ''

main()
