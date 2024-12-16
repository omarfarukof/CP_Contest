import numpy as np

def mode(a:np.ndarray) -> np.ndarray:
    values, counts = np.unique(a, return_counts=True)
    max_count = np.max(counts)
    m = values[counts == max_count] 
    return m


if __name__ == "__main__":
    a = np.array([4,1,5,3,4,5,1])
    print(type(a))
    print(mode(a))