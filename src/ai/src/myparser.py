import getopt
import myexception

def parse_data(argv:list) -> int:
    port:int = None
    name:str = None
    machine:str = None
    shortopts:str = "p:n:h:"

    args, values = getopt.getopt(argv[1:], shortopts)
    for current_arg, current_value in args:
        if current_arg in "-p":
            if (port != None):
                raise myexception.Exception("duplicated port's option")
            try:
                port = int(current_value)
            except:
                raise myexception.Exception("drovide a valid port")
        elif current_arg in "-n":
            if (name != None):
                raise myexception.Exception("duplicated name's option")
            name = current_value
        elif current_arg in "-h":
            if (machine != None):
                raise myexception.Exception("duplicated machine's option")
            machine = current_value

    # Check if all values are valid
    if (port == None or port < 0):
        raise myexception.Exception("provide a valid port")
    if (name == None):
        raise myexception.Exception("provide a name")
    if (machine == None):
        machine = "localhost"
    return port, name, machine