using UnityEngine;
using System.Collections;

public class SekigaeLogic {
    static public ArrayList Sekigsae(ArrayList array)
    {
        ArrayList newArray = new ArrayList(array.Count);
        foreach (var n in array) 
        {
            var index = Random.Range(0, newArray.Count+1);
            newArray.Insert(index, n);
        }
        return newArray;
    }
}
