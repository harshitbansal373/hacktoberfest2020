import time


def elapsed_time(func):
    def wrapper(*args, **kwargs):
        beg_ts = time.time() * 1000
        retval = func(*args, **kwargs)
        end_ts = time.time() * 1000
        print("Function %s - elapsed time: %.2f (ms)" % (func.__name__, end_ts - beg_ts))
        return retval

    return wrapper


@elapsed_time
def my_function():
    time.sleep(5)


if __name__ == '__main__':
    my_function()
