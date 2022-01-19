import java.io.IOException
import java.lang.*
import java.util.*

var sb = StringBuilder()
var scan = FastReader()
var s = mutableSetOf<Int>()
var A = 0
var B = 0
fun input() {
    for(i in 0..9) {
        val value = scan.nextInt()
        s.add(value % 42)
    }
}

fun pro() {
    println(s.size)
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

