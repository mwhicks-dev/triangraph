# triangraph

TrianGraph is a C++ solver for the problem of creating graph triangulations from a point set that satisfy certain solution criteria. 

The structure of this repository is borrowed from some combination of [grapph](https://github.com/mwhicks-dev/grapph) and [SPlat](https://github.com/mwhicks-dev/SPlat), my best and my most fun C++ projects respectively to date. The branch-and-bound implementation is modeled after one created by my undergraduate research mentor, [Dr. Matt Stallmann](https://mfms.wordpress.ncsu.edu/), who is responsible for my interest in experimental algorithms and computer science research.

## Docker Unit Testing

```bash
docker build -t tgr_test .

docker run --rm tgr_test
```

Automated CMakeLists build. See [grapph's testing build](https://github.com/mwhicks-dev/grapph/blob/main/README.md#testing-build) for info on what all this does, as it is functionally identical.
