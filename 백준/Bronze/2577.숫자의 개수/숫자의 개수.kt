import java.io.IOException
import java.lang.*
import java.util.*

var sb = StringBuilder()
var scan = FastReader()
var A = 0
var B = 0
var C = 0
var arr = IntArray(10)
fun input() {
    A = scan.nextInt()
    B = scan.nextInt()
    C = scan.nextInt()
}

fun pro() {
    var value = A * B * C
    while(value > 0) {
        arr[value % 10]++
        value /= 10
    }
    for(i in 0..9) {
        sb.append(arr[i]).append("\n")
    }
    println(sb.toString())
}

fun main() {
    input()
    pro()
}

class FastReader {
    var br = System.`in`.bufferedReader()
    var st: StringTokenizer? = null
    operator fun next(): String {
        while (st == null || !st!!.hasMoreElements()) {
            try {
                st = StringTokenizer(br.readLine())
            } catch (e: IOException) {
                e.printStackTrace()
            }
        }
        return st!!.nextToken()
    }

    fun nextInt(): Int {
        return next().toInt()
    }

    fun nextLong(): Long {
        return next().toLong()
    }

    fun nextDouble(): Double {
        return next().toDouble()
    }

    fun nextLine(): String {
        var str = ""
        try {
            str = br.readLine()
        } catch (e: IOException) {
            e.printStackTrace()
        }
        return str
    }

}

