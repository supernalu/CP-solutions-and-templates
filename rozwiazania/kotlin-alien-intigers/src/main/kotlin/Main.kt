import kotlin.math.abs
fun readString() = readLine()!!
fun readStrings() = readString().split(" ")
fun readInt() = readString().toInt()
fun readInts() = readStrings().map { it.toInt() }
fun readLong() = readString().toLong()
fun readLongs() = readStrings().map { it.toLong() }
fun readDouble() = readString().toDouble()
fun readDoubles() = readStrings().map { it.toDouble() }

operator fun String.times(n: Int): String {
    val sb = StringBuilder()
    repeat(n) {
        sb.append(this)
    }
    return sb.toString()
}

fun main() {
    val n = readString()
    val siz = n.length
    var been = arrayOf(0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    for (dig in n) {
        been[dig.digitToInt()] = 1
    }
    var poss = 0
    been.forEach {
        if (it == 0) {
            poss = 1
        }
    }
    if (poss == 0) {
        print("Impossible")
        return
    }
    poss = 0
    for (dig in 1..9) {
        if (been[dig] == 0) {
            poss = 1
        }
    }
    if (poss == 0) {
        print("0")
        return
    }
    var bigger = ""
    val first = n[0].digitToInt()
    poss = 0
    for (dig in first..9) {
        if (been[dig] == 0) {
            poss = 1;
            bigger = bigger + dig.toString()
            break
        }
    }
    if (poss == 1) {
        for (dig in 0..9) {
            if (been[dig] == 0) {
                for (itt in 1..siz-1) {
                    bigger = bigger + dig.toString()
                }
                break
            }
        }
    }
    var smaller = ""
    var tmp = 0
    for (dig in 0..first) {
        if (been[dig] == 0) {
            tmp = dig
        }
    }
    smaller += tmp.toString()
    tmp = 0
    for (dig in 0..9) {
        if (been[dig] == 0) {
            tmp = dig
        }
    }
    for (itt in 1..siz-1) {
        smaller = smaller + tmp.toString()
    }
    var muchBigger = ""
    for (dig in 1..9) {
        if (been[dig] == 0) {
            muchBigger = muchBigger + dig.toString()
            break
        }
    }
    for (dig in 0..9) {
        if (been[dig] == 0) {
            for (itt in 0..siz-1) {
                muchBigger = muchBigger + dig.toString()
            }
            break
        }
    }
    //print(smaller)
    //print(' ')
    //print(bigger)
    //print('\n')
    //print(muchBigger)
    //print(' ')

    var res = minOf(abs(muchBigger.toLong()-n.toLong()), abs(smaller.toLong()-n.toLong()))
    if (bigger.length > 0)
     res = minOf(res, abs(bigger.toLong()-n.toLong()))
    if (abs(smaller.toLong()-n.toLong()) == res) {
        print(smaller.toLong())
        print(' ')
    }
    if (bigger.length > 0 && abs(bigger.toLong()-n.toLong()) == res) {
        print(bigger.toLong())
        print(' ')
    }
    if (abs(muchBigger.toLong()-n.toLong()) == res) {
        print(muchBigger.toLong())
        print(' ')
    }
}