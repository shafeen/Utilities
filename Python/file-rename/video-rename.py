#!/usr/bin/python

import sys
from os import listdir, getcwd, rename as filerename
from os.path import isfile, join as pathjoin
from string import join as strjoin

argv = sys.argv


def getPrefixFilter(testPrefix):
    def filterFunc(fileName):
        try:
            return fileName.index(testPrefix) == 0
        except ValueError:
            return False
    return filterFunc


def getPrefixArg():
    PREFIX_ARG = '--prefix='
    errMsg = 'You must specify: %s!' % PREFIX_ARG
    if len(argv) < 2:
        raise RuntimeError(errMsg)
    elif not getPrefixFilter(PREFIX_ARG)(argv[1]):
        raise RuntimeError(errMsg)
    else:
        prefix = strjoin(argv[1].split(PREFIX_ARG), '')
        if len(prefix) == 0:
            raise RuntimeError('the prefix cannot be empty')
        else:
            return prefix


def getDelimiterArg():
    #TODO: complete & test this function
    PREFIX_ARG = '--delimiter='
    errMsg = 'You must specify: %s!' % PREFIX_ARG
    if len(argv) != 3:
        raise RuntimeError(errMsg)
    elif not getPrefixFilter(PREFIX_ARG)(argv[2]):
        raise RuntimeError(errMsg)
    else:
        delimiter = strjoin(argv[2].split(PREFIX_ARG), '')
        if len(delimiter) == 0:
            raise RuntimeError('the delimiter cannot be empty')
        elif len(delimiter) > 1:
            raise RuntimeError('the delimiter must be a single character, you typed "%s"' % delimiter)
        else:
            return delimiter


def getRequiredArgs():
    prefix = getPrefixArg()
    delimiter = getDelimiterArg()
    if not confirmWithMsg("Use prefix: '%s'? Y/n:" % prefix):
        exit()
    if not confirmWithMsg("Use delimiter: '%s'? Y/n:" % delimiter):
        exit()
    return [prefix, delimiter]


def getOnlyFilesInDir(dirPath):
    onlyfiles = [f for f in listdir(dirPath) if isfile(pathjoin(dirPath, f))]
    return onlyfiles


def getFilesWithPrefix(fileList, prefix):
    return filter(getPrefixFilter(prefix), fileList)


def confirmWithMsg(msg):
    confirmed = raw_input(msg) == "Y"
    confirmMsg = "Confirmed" if confirmed else "Cancelling"
    print confirmMsg
    return confirmed


# find common string fragments in the list of files
def getCommonFragmentCounts(filenames, delimiter):
    commonFragmentCounts = {}

    for myfile in filenames:
        filenameSplit = myfile.split('.')
        fileExt = filenameSplit[-1]
        filenameMinusExt = strjoin(filenameSplit[:-1], '.')

        commonDelimiters = [delimiter]
        filenameFragments = {()}
        for delimiter in commonDelimiters:
            filenameSplit = filenameMinusExt.split(delimiter)
            # print 'split %s into ' % filenameMinusExt, filenameSplit, 'using %s' % delimiter
            for filenameFragment in filenameSplit:
                filenameFragments.add(filenameFragment)
        print 'fragments in file: %s' % myfile, filenameFragments

        for filenameFragment in filenameFragments:
            if type(filenameFragment) != str:
                continue
            if filenameFragment in commonFragmentCounts:
                commonFragmentCounts[filenameFragment] += 1
            else:
                # print 'saving fragment %s' % filenameFragment
                commonFragmentCounts[filenameFragment] = 1

    return commonFragmentCounts


def getFragmentEliminationList(commonFragmentCounts):
    # display a list of potential fragments to eliminate
    print 'common fragment counts (> 1):'
    potentialFragmentsToDelete = []
    for fragment, count in commonFragmentCounts.iteritems():
        if count > 1:
            print fragment, count
            potentialFragmentsToDelete.append(fragment)

    # ask the user to create the final list of fragments to eliminate
    fragmentsToDelete = []
    fragmentDeletePrompt = 'Fragment to eliminate (q to stop): '
    userStr = raw_input(fragmentDeletePrompt)
    while userStr != 'q':
        if userStr in commonFragmentCounts:
            fragmentsToDelete.append(userStr)
        else:
            print 'Invalid fragment chosen, please try again.'
        print fragmentsToDelete
        userStr = raw_input(fragmentDeletePrompt)

    if not confirmWithMsg('delete the following fragments? %s (Y/n):' % fragmentsToDelete):
        exit()
    return fragmentsToDelete

# filerename(currentDirFiles[2], 'renamed.py')


def run():
    currentDirFiles = getOnlyFilesInDir(getcwd())
    print currentDirFiles

    prefix, delimiter = getRequiredArgs()

    filesWithPrefix = getFilesWithPrefix(currentDirFiles, prefix)
    print "All files in directory with prefix '%s': \n%s" % (prefix, filesWithPrefix)
    if not confirmWithMsg('Continue? (Y/n): '):
        exit()

    commonFragmentCounts = getCommonFragmentCounts(filesWithPrefix, delimiter)

    fragmentsToDelete = getFragmentEliminationList(commonFragmentCounts)

    # eliminate the fragments from each of the relevant files
    renameEnabled = confirmWithMsg('Run in rename mode? Y=yes/n=demo mode : ')
    for myfile in filesWithPrefix:
        filenameSplit = myfile.split('.')
        fileExt = '.' + filenameSplit[-1]
        oldFilenameMinusExt = strjoin(filenameSplit[:-1], '.')
        newFilenameMinusExt = oldFilenameMinusExt
        for fragment in fragmentsToDelete:
            newFilenameMinusExt = strjoin(newFilenameMinusExt.split(fragment), '').strip().strip(delimiter).strip()
        oldFilename, newFilename = oldFilenameMinusExt+fileExt, newFilenameMinusExt+fileExt
        print 'renaming %s to %s' % (oldFilename, newFilename)
        if renameEnabled:  # do the actual rename operation here when production ready!
            filerename(oldFilename, newFilename)

run()



