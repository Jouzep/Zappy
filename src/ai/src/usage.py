import sys

def show_usage(fd) -> None:
    """
    Display the usage information about the ai program. About how to use it.

    Args:
        fd (_type_): The output file descriptor where the usage message should be printed
    """
    print("USAGE: %s -p port -n name -h machine" % (sys.argv[0]), file=fd)
    print("\tport\tis the port number", file=fd)
    print("\tname\tis the name of the team", file=fd)
    print("\tmachine\tis the name of the machine; localhost by default", file=fd)