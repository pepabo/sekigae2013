using UnityEngine;
using System.Collections;

public class SekigaeLogic {
    static public ArrayList Sekigsae(ArrayList array)
    {
        ArrayList newArray = new ArrayList(array.Count);
        foreach (var n in array) { newArray.Insert(Random.Range(0, newArray.Count), n); }
        return newArray;
    }
}
