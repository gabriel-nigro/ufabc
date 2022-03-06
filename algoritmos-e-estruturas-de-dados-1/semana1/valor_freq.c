#include "valor_freq.h"

int valor_frequente(int v[], int n)
{
  int freq, maxFreq = 0, mostFreqNumber;
  for (int i = 0; i < n; i++)
  {
    freq = -1;
    for (int j = 0; j < n; j++)
    {
      if (v[i] == v[j])
      {
        freq++;
      }
    }
    if (freq > maxFreq)
    {
      maxFreq = freq;
      mostFreqNumber = v[i];
    }
  }
  return mostFreqNumber;
}