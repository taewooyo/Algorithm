import java.io.IOException
import java.lang.*
import java.util.*

var sb = StringBuilder()
var scan = FastReader()

var N = 0
var M = 0
var dna = Array(1000) {CharArray(50)}

fun input() {
    N = scan.nextInt()
    M = scan.nextInt()
    for (i in 0 until N) {
        dna[i] = scan.nextLine().toCharArray()
    }
}
var answer = 0
var cnt = 0
fun pro() {
    val hamming = IntArray(M)

    for(i in 0 until M) {
        val mp = mutableMapOf<Char, Int>()
        for(j in 0 until N) {
            if(mp.containsKey(dna[j][i])) {
                mp[dna[j][i]] = mp[dna[j][i]]!! + 1
            }
            else {
                mp[dna[j][i]] = 1
            }
        }

        var ret = mp.toList().sortedWith { o1, o2 ->
            if (o1.second == o2.second) o2.first - o1.first
            else o1.second - o2.second
        }
        sb.append(ret[ret.size - 1].first)
        cnt += N - ret[ret.size - 1].second
    }
    sb.append("\n").append(cnt)
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