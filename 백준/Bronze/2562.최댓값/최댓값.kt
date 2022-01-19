import java.io.IOException
import java.lang.*
import java.util.*

var sb = StringBuilder()
var scan = FastReader()

fun input() {
    var max = 0
    var idx = 0
    for(i in 1..9) {
        val value = scan.nextInt()
        if(max < value) {
            max = value
            idx = i
        }
    }
    sb.append(max).append("\n").append(idx)
    println(sb.toString())
}

fun pro() {
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

