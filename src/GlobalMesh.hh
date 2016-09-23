/*
 * GlobalMesh.hh
 *
 *  Created on: Aug 8, 2016
 *      Author: jgraham
 */

#ifndef GLOBALMESH_HH_
#define GLOBALMESH_HH_

#include "InputParameters.hh"
#include "LogicalUnstructured.hh"
#include "Parallel.hh"

class GlobalMesh {
public:
	GlobalMesh(const InputParameters& input_params,
			Context ctx, HighLevelRuntime* runtime);
	virtual ~GlobalMesh();

	std::vector<PhaseBarrier> phase_barriers;
	std::vector<LogicalRegion> lregions_halo;
	std::vector<std::vector<int>> masters;

    LogicalUnstructured zones;
    LogicalUnstructured points;

private:
	void init();
	void allocateGhostPointFields();

	FieldSpace fSpaceGhostPoints;

	const InputParameters inputParams;
	int numZones;
	int numPoints;
	Context ctx;
	HighLevelRuntime* runtime;
};

#endif /* GLOBALMESH_HH_ */
