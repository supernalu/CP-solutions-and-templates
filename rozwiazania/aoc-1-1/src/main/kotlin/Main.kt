import java.io.InputStream
import java.io.File
import java.lang.Integer.min
import java.lang.Math
fun sumuj(s: String) : Int
{
    val digits = listOf("one", "two", "three", "four", "five", "six", "seven", "eight", "nine")
    var res = 0
    var ig = 0
    for (it in s) {
        if ((it >= '0' && it <= '9')) {
            val tmp = it.digitToInt()
            res = 10 * res + tmp
            break
        }
        var tmp = 1
        var done = 0
        for (dig in digits) {
            val b = s.length
            if (s.substring(ig, min(ig+dig.length, b-1)) == dig)
            {
                res = 10*res + tmp
                done = 1
                break
            }
            tmp += 1
        }
        if (done == 1)
            break
        ig+=1
    }
    ig = 0
    for (it in s.reversed()) {
        if (it >= '0' && it <= '9') {
            val tmp = it.digitToInt()
            res = 10 * res + tmp
            break
        }
        var tmp = 1
        var done = 0
        for (dig in digits) {
            val b = s.length
            if (s.reversed().substring(ig, min(ig+dig.length, b-1)) == dig.reversed())
            {
                res = 10*res + tmp
                done = 1
                break
            }
            tmp += 1
        }
        if (done == 1)
            break
        ig+=1
    }
    return res
}
fun main(args: Array<String>) {
    val inp: InputStream = File("D:\\N-L\\rozwiazania\\aoc-1-1\\src\\main\\kotlin\\testcase.txt").inputStream()
    val tab = mutableListOf<String>()
    inp.bufferedReader().forEachLine { tab.add(it) }
    tab.forEach{println(">  " + it)}
    var res = 0
    tab.forEach{res += sumuj(it)}
    println(res)
    println(sumuj(tab.first()))
}