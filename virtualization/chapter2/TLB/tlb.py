import subprocess
import sys
import os
import matplotlib.pyplot as plt
if __name__ == "__main__":
    i = 1
    #subprocess.call("gcc -o tlb tlb.c", shell=True)
    subprocess.call("gcc -O0 -o tlb tlb.c", shell=True)

    y = []
    while i < 8193:
        TRIAL = str(500)
        NUMPAGES = str(i)
        cmd = ["/Users/wangdake/Desktop/ostep/virtualization/chapter2/TLB/tlb", NUMPAGES, TRIAL]
        print()
        print("the numpages is " + NUMPAGES + "\nThe trial is " + TRIAL);
        sys.stdout.flush()
        i *= 2
        ret = subprocess.Popen(cmd, stdout=subprocess.PIPE)
        data=ret.stdout.read().decode('utf-8')
        print(float(data))
        y.append(float(data))
    plt.figure(1);
    plt.plot(range( len(y)),y)
    plt.xlabel("NUMPAGES")
    plt.ylabel("TIME PER PAGE(ns)")
    plt.xticks(range(len(y)), [2**x for x in range(len(y))])
    #plt.savefig("tlb_withO0.png")
    #plt.savefig("tlb_withoutO0.png")
    plt.savefig("tlb_withcalloc.png")
    plt.show()
    