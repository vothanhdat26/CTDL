def merge(list, leftlist, rightlist):
    len(list)  # do dai
    len(leftlist)
    len(rightlist)
    a = 0 # chi so ban dau cua mang con dau tien
    b = 0 # chi so ban dau cua mang con dau tien
    c = 0 # chi so ban dau cua mang con dau tien
    while a < len(leftlist) and b < len(rightlist):
        if leftlist[a] <= rightlist[b]:
            list[c] = leftlist[a]
            a += 1  # a++ else:
        else:
            list[c] = rightlist[b]
            b += 1
        c += 1
    while a < len(leftlist):
        list[c] = leftlist[a]
        a += 1
        c += 1
    while b < len(rightlist):
        list[c] = rightlist[b]
        b += 1
        c += 1


def natural_mergeSort(list):
    m = 0
    n = 0
    while m < len(list):
        if m < len(list)-1:
            if list[m] < list[m+1]:
                m += 1
                continue
        leftlist = list[0:n]
        rightlist = list[n:m+1]
        merge(list, leftlist, rightlist)
        m += 1
        n = m


if __name__ == "__main__":
    list = [1, 4, 2, 3, 6, 7, 5, 9, 10, 8]
    print("Danh sach truoc khi sap xep: ")
    print(list)
    natural_mergeSort(list)
    print("danh sach sau khi sap xep:")
    print(list)
# vo thanh dat 19200270
