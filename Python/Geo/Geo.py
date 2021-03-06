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


# find all GPS coordinate indexes that are within "milesRadius" miles or less
# only return the "maxDrivers" closest driver indexes if "maxDrivers" specified
# the "maxDrivers" indexes have to be the closest ones,
# i.e. if there are 6 total but "maxDrivers" == 2, return the 2 closest indexes
# NOTE: be aware that "mileRadius" must be a valid number
def getGpsCoordIndexesWithinRadius(latBase, lonBase, latLonList, mileRadius, maxDrivers=None):
    haversineDistances = haversine_dist_mi_numpy_latlng(latBase, lonBase, latLonList)
    haversineIndexes = range(len(haversineDistances))

    gpsIndexesWithinRadius = [i for i in haversineIndexes if haversineDistances[i] <= mileRadius]

    # make a sorted list associating every haversineDistance with its index in the array
    # NOTE: we are only keeping the haversine distances within radius in the list
    haversineDistIndexTupleList = [(haversineDistances[i], i) for i in gpsIndexesWithinRadius]
    haversineDistIndexTupleList = sorted(haversineDistIndexTupleList, key=lambda tup: tup[0])

    # limit the number of coordinates if "maxDrivers" is specified
    if maxDrivers and 0 < maxDrivers < len(haversineDistIndexTupleList):
        haversineDistIndexTupleList = haversineDistIndexTupleList[0:maxDrivers]

    # gpsIndexesWithinRadius will now be in the order low-to-high for the haversine distances
    gpsIndexesWithinRadius = [haversineDistIndexTupleList[i][1] for i in range(len(haversineDistIndexTupleList))]
    return gpsIndexesWithinRadius


# find all GPS coordinates that are within "milesRadius" miles or less
# only return the "maxDrivers" closest drivers if "maxDrivers" specified
# NOTE: the returned gps coordinates will be sorted from closest to farthest
def getGpsCoordsWithinRadius(latBase, lonBase, latLonList, mileRadius, maxDrivers=None):
    latList, lonList = latLonList[0::2], latLonList[1::2]
    gpsCoordList = [[latList[i], lonList[i]] for i in range(0, len(latList))]

    gpsIndexesWithinRadius = getGpsCoordIndexesWithinRadius(latBase, lonBase, latLonList, mileRadius, maxDrivers)

    gpsCoordsWithinRadius = [gpsCoordList[i] for i in gpsIndexesWithinRadius]
    return gpsCoordsWithinRadius







