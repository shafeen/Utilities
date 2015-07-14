#!/usr/bin/env python

# Author : Shafeen M.

# tools to determine distances between 2 (or more) GPS coordinates
# provided the latitudes and logitudes of the coords are given in the
# appropriate form


import numpy as np
from math import radians, cos, sin, asin, sqrt


# Returns dist between 2 points in km
def haversine_dist_km(lon1, lat1, lon2, lat2):
    """
    Calculate the great circle distance between two points
    on the earth (specified in decimal degrees) in kilometers (km)
    """
    # convert decimal degrees to radians
    lon1, lat1, lon2, lat2 = map(radians, [lon1, lat1, lon2, lat2])

    # haversine formula
    dlon = lon2 - lon1
    dlat = lat2 - lat1
    a = sin(dlat/2)**2 + cos(lat1) * cos(lat2) * sin(dlon/2)**2
    c = 2 * asin(sqrt(a))

    # 6367 km is the radius of the Earth
    km = 6367 * c
    return km


# Returns dist between 2 points in miles
def haversine_dist_mi(lon1, lat1, lon2, lat2):
    """
    Calculate the great circle distance between two points
    on the earth (specified in decimal degrees) in miles (mi)
    """
    MILE_TO_KM = 1.60934
    return haversine_dist_km(lon1, lat1, lon2, lat2)/MILE_TO_KM


# uses numpy
def haversine_dist_mi_numpy(lonBase, latBase, lonLatList):
    """
    Calculate the great circle distance between 1 base GPS point on the earth
    (specified in decimal degrees) and many other GPS points and return the
    distances between each point in
    """
    # convert the list to a numpy array
    # also converted decimal degrees to radians
    lonLatList = (np.vectorize(radians))(lonLatList)

    # convert base decimal degrees to radians
    lonBase, latBase = map(radians, [lonBase, latBase])

    # haversine formula
    dlonArray = lonLatList[0::2] - lonBase
    dlatArray = lonLatList[1::2] - latBase
    a = (np.sin(dlatArray/2))**2 + np.cos(latBase) * np.cos(lonLatList[1::2]) * (np.sin(dlonArray/2))**2
    c = 2 * np.arcsin(np.sqrt(a))

    # 6367 km is the radius of the Earth
    km = 6367 * c
    mi = km/1.60934
    return mi


# same as haversine_dist_mi_numpy() but lat and lon positions reversed
def haversine_dist_mi_numpy_latlng(latBase, lonBase, latLonList):
    """
    Calculate the great circle distance between two points
    on the earth (specified in decimal degrees)
    """
    # convert the list to a numpy array
    # also converted decimal degrees to radians
    latLonList = (np.vectorize(radians))(latLonList)

    # convert base decimal degrees to radians
    lonBase, latBase = map(radians, [lonBase, latBase])

    # haversine formula
    dlatArray = latLonList[0::2] - latBase
    dlonArray = latLonList[1::2] - lonBase
    a = (np.sin(dlatArray/2))**2 + np.cos(latBase) * np.cos(latLonList[0::2]) * (np.sin(dlonArray/2))**2
    c = 2 * np.arcsin(np.sqrt(a))

    # 6367 km is the radius of the Earth
    km = 6367 * c
    mi = km/1.60934
    return mi


def _idx_smallest(someArray):
    """
    Given 'someArray', it will loop thru the contents and return
    the index of the element with the smallest value.
    Will return index 0 if length is 1
    NOTE: someArray length MUST NOT BE ZERO!!
    """
    arrayLen = len(someArray)
    idxSmallest = 0
    for idx in xrange(arrayLen):
        if someArray[idx] < someArray[idxSmallest]:
            idxSmallest = idx

    return idxSmallest


def _benchmark_run():
    lonLat1 = (-96.821275, 32.929494)
    lonLat2 = (-96.822074, 32.939674)
    # print haversine_dist_mi(32.929494, -96.821275, 32.968531, -96.821533)
    # print haversine_dist_mi_numpy(32.929494, -96.821275, [32.929506, -96.803515])
    # print haversine_dist_mi(32.929494, -96.821275, 32.929506, -96.803515)

    numOperations = 1000
    # numOperations = int(raw_input("Enter number of operations to perform: "))
    # benchmarking performance for the regular version of the function call
    # for i in range(numOperations):
    #     haversine_dist_mi(lonLat1[0], lonLat1[1], lonLat2[0], lonLat2[1])

    # benchmarking performance for the numpy version of the function call
    haversine_dist_mi_numpy(lonLat1[0], lonLat1[1], [lonLat2[0], lonLat2[1]]*numOperations)

    # lonLatArray = [(lonLat1,lonLat2)]*10000
    # for lonLat in lonLatArray:
    # 	haversine_dist_mi(lonLat[0][0], lonLat[0][1], lonLat[1][0], lonLat[1][1])



# functions below limit/filter search domain in various ways:
'''
Need a function that can give me X closest drivers within N miles of the driver.
'''


# find all GPS coords that are within "milesRadius" miles or less
def getClosestGpsCoords(latBase, lonBase, latLonList, mileRadius):
    latList, lonList = latLonList[0::2], latLonList[1::2]
    gpsCoordList = [[latList[i], lonList[i]] for i in range(0, len(latList))]

    haversineDistances = haversine_dist_mi_numpy_latlng(latBase, lonBase, latLonList)
    haversineIndexes = range(0, len(haversineDistances))

    closestGpsIndexes = [i for i in haversineIndexes if haversineDistances[i] <= mileRadius]

    gpsCoordsWithinRadius = [gpsCoordList[i] for i in closestGpsIndexes]
    return gpsCoordsWithinRadius








