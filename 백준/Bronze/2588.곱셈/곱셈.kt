import java.lang.*
import java.util.*

fun main() {
    val br = System.`in`.bufferedReader()
    val str = StringBuilder()

    var a = br.readLine().toString().toInt()
    var b = br.readLine().toString().toInt()
    val last = a * b
    while(b != 0) {
        val mod = b % 10
        var result = mod * a
        str.append("$result\n")
        b /= 10
    }
    str.append("$last")
    println(str.toString())
    br.close()
}