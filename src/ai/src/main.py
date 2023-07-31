#!/usr/bin/env python3

import sys

# Include relative path of the source files from the root
sys.path.append('src/ai/src')

from myparser import parse_data
import usage
from zappy_ai import AI
import myexception
from getopt import GetoptError

def main(argv:list) -> int:
    if len(argv) == 2 and argv[1] == "-help":
        usage.show_usage(sys.stdout)
        return 0
    try:
        port, name, machine = parse_data(argv)
    except (myexception.Exception, GetoptError) as e:
        print("Parser: %s" % (e), file=sys.stderr)
        return 84

    try:
        ai = AI(port, machine, name)
        ai.run_ai()
    except myexception.Exception as e:
        print("%s: %s" % (sys.argv[0], e), file=sys.stderr)
        return 84
    return 0

if __name__ == "__main__":
    exit(main(sys.argv))
