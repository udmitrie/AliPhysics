AliAnalysisTaskPP13 * AddAnalysisTaskPP(
	Bool_t isMC = kFALSE,
	TString description = "",
	TString suff = ""
)
{
	// Restore the analysis manager
	//
	AliAnalysisManager * manager = AliAnalysisManager::GetAnalysisManager();

	// Setup Analysis Selections
	//
	TList * selections = new TList();

	AliPP13ClusterCuts cuts_pi0 = AliPP13ClusterCuts::GetClusterCuts();
	AliPP13ClusterCuts cuts_eta = AliPP13ClusterCuts::GetClusterCuts();
	cuts_eta.fAsymmetryCut = 0.7;


	if (!isMC)
	{
		// TODO: Add plain selections
		AliPP13SelectionWeights & data_weights = AliPP13SelectionWeights::Init(AliPP13SelectionWeights::kData);
		AliPP13SelectionWeights & data_weights_plain = AliPP13SelectionWeights::Init(AliPP13SelectionWeights::kPlain);

		selections->Add(new AliPP13SpectrumSelection("Phys", "Physics Selection", cuts_pi0, &data_weights));
		selections->Add(new AliPP13SpectrumSelection("PhysPlain", "Physics Selection no TOF cut efficiency", cuts_pi0, &data_weights_plain));
		selections->Add(new AliPP13PhotonTimecutStudySelection("Time", "Testing Timing Selection", cuts_pi0, &data_weights));

		selections->Add(new AliPP13SpectrumSelection("Eta", "Physics Selection for eta meson", cuts_eta, &data_weights));
		selections->Add(new AliPP13SpectrumSelection("EtaPlain", "Physics Selection for eta meson no TOF cut efficiency", cuts_eta, &data_weights_plain));
		selections->Add(new AliPP13PhotonTimecutStudySelection("EtaTime", "Testing Timing Selection for eta meson", cuts_eta, &data_weights));

		selections->Add(new AliPP13TagAndProbeSelection("TagAndProbleTOF", "Cluster p_{T} Selection", cuts_pi0, &data_weights));
		selections->Add(new AliPP13NonlinearitySelection("PhysNonlin", "Physics efficiency for neutral particles", cuts_pi0, &data_weights));
		selections->Add(new AliPP13NonlinearitySelection("PhysNonlinPlain", "Physics efficiency for neutral particles", cuts_pi0, &data_weights_plain));

		selections->Add(new AliPP13QualityPhotonSelection("Qual", "Cluster quality Selection", cuts_pi0, &data_weights));
		selections->Add(new AliPP13PhotonSpectrumSelection("PhotonsTime", "Cluster p_{T} Selection with timing cut", cuts_pi0, &data_weights, 10., 3.));

		selections->Add(new AliPP13PhotonSpectrumSelection("Photons", "Cluster p_{T} Selection", cuts_pi0, &data_weights));
		selections->Add(new AliPP13PhotonSpectrumSelection("PhotonsPlain", "Cluster p_{T} Selection", cuts_pi0, &data_weights_plain));
		selections->Add(new AliPP13EpRatioSelection("EpRatio", "E/p ratio selection for electrons", cuts_pi0, &data_weights));

		delete &data_weights;
		delete &data_weights_plain;
	}


	if (isMC)
	{
		AliPP13SelectionWeightsMC & mc_weights = AliPP13SelectionWeights::Init(AliPP13SelectionWeights::kMC);
		AliPP13SelectionWeightsMC & mc_weights_only = AliPP13SelectionWeights::Init(AliPP13SelectionWeights::kMC);

		mc_weights_only.fNonGlobal = 1.0;
		mc_weights_only.fNonA = 0.0;

		selections->Add(new AliPP13EfficiencySelectionMC("PhysEff", "Physics efficiency for neutral particles fully corrected", cuts_pi0, &mc_weights));
		selections->Add(new AliPP13EfficiencySelectionMC("PhysEffEta", "Physics efficiency for neutral particles with asymmetry fully corrected", cuts_eta, &mc_weights));
		selections->Add(new AliPP13EfficiencySelectionMC("PhysEffPlain", "Physics efficiency for neutral particles, no nonlinearity", cuts_pi0, &mc_weights_only));

		selections->Add(new AliPP13NonlinearitySelection("PhysNonlin", "Physics nonlinearity for neutral particles", cuts_pi0, &mc_weights, kTRUE));
		selections->Add(new AliPP13NonlinearitySelection("PhysNonlinRaw", "Raw nonlinearity for neutral particles", cuts_pi0, &mc_weights_only, kTRUE));

		selections->Add(new AliPP13NonlinearityScanSelection("PhysNonlinScan", "Physics efficiency for neutral particles", cuts_pi0, &mc_weights));
		selections->Add(new AliPP13MesonSelectionMC("MCStudy", "MC Selection with timing cut", cuts_pi0, &mc_weights));
		selections->Add(new AliPP13KaonToPionRatioMC("KaonToPionRatio", "MC Selection for pion/kaon ratio", cuts_pi0, &mc_weights));
		selections->Add(new AliPP13EpRatioSelection("EpRatio", "E/p ratio selection for electrons", cuts_pi0, &mc_weights));
		selections->Add(new AliPP13FeeddownSelection("FeeddownSelectionPlain", "FeeddownSelection", cuts_pi0, &mc_weights));
		AliPP13SelectionWeightsMC & mc_weights_feeddown = AliPP13SelectionWeights::Init(AliPP13SelectionWeights::kFeeddown);
		selections->Add(new AliPP13FeeddownSelection("FeeddownSelection", "FeeddownSelection", cuts_pi0, &mc_weights_feeddown));

		delete & mc_weights;
		delete & mc_weights_only;
		delete & mc_weights_feeddown;
	}

	// Setup the main task
	//
	AliAnalysisTaskPP13 * task = new AliAnalysisTaskPP13("PhosProtons", selections);
	manager->AddTask(task);
	manager->ConnectInput(task, 0, manager->GetCommonInputContainer());
	AliAnalysisDataContainer * coutput = 0;
	for (Int_t i = 0; i < task->GetSelections()->GetEntries(); ++ i)
	{
		AliPP13PhysicsSelection * fSel = dynamic_cast<AliPP13PhysicsSelection *> (task->GetSelections()->At(i));
		fSel->SetTitle(description);
		cout << fSel->GetTitle() << endl;

		coutput = manager->CreateContainer(
			fSel->GetName() + suff,
			TList::Class(),
			AliAnalysisManager::kOutputContainer,
			AliAnalysisManager::GetCommonFileName()
		);

		manager->ConnectOutput(task, i + 1, coutput);
	}
	return task;
}
