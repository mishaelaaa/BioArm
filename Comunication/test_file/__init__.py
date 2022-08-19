import time

cvsfile = open("test.csv", "w")   # declare file for writing

def go():
    i = 0
    with open("/home/some/dir/test.csv", "a") as nice:
        while True:
            nice.write(f"hello,{i},{time.time()}\n")
            i += 1
            time.sleep(5)


if __name__ == "__main__":
    go()
